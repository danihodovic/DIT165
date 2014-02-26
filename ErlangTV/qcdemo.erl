%% 
%% Code presented during supervision on Wednesday 2014-02-19
%%
-module (qcdemo).

-include_lib("eqc/include/eqc.hrl").

-compile(export_all).


%% Test for lists:seq/2 function

prop_seq2() -> ?FORALL(
			   {From,To}, {int(),int()},
			   collect({From, To}, 
					   try 
						   List = lists:seq(From,To),
						   length(List) == (To - From + 1)
					   catch
						   error:E -> 
							   NegList = lists:seq(To, From),
							   -length(NegList) == To - From - 1
					   %%(To-From+1)  0
					   end)).
prop_1() ->
	?FORALL(
	{From, To, Inc}, gen_ints(),
	collect({From, Inc, To}, 
			try
				List = lists:seq(From, To, Inc),
				[H|_] = List,
				
				%%Test1
				From == H,
				%%Test2
				is_inc(List, Inc) == true
			catch error:Error -> Error
			end)).

gen_ints() ->	
	R = round(random:uniform() * 1),
	case R of
		0 -> gen_positive();
		1 -> gen_negative()
	end.

gen_positive() ->
	Min = -100000,
	Max = 100000,
	First = choose(Min, -1), 
	Last = choose(1, Max * 10),
	Inc = choose(1, Max * 10),
	{First, Last, Inc}.

gen_negative() ->
	Min = -100000,
	Max = 100000,
	First = choose(1, Max), 
	Last = choose(Min * 10, -1),
	Inc = choose(Min * 10, -1),
	{First, Last, Inc}.


is_inc([_|[]], _) ->
	true;
is_inc([H, H2|T], Inc) ->
	%% 	io:format("H: ~p, H2: ~p, Inc: ~p~n", [H, H2, Inc]),
	case H2 - H of
		Inc -> is_inc([H2|T], Inc)
	end.

prop_2() ->
	prop_2_help(ints),
	prop_2_help(atoms),
	prop_2_help(mixed).


prop_2_help(Command) ->
	?FORALL(
	{OriginalList}, {genRandomList(Command)},
	collect(OriginalList, 
			try
			%% Test1 - Remove nonexist item list is unchanged
				MutatedList = lists:delete("test", OriginalList),
				MutatedList == OriginalList,
				
			%% Test2 - Remove exist item, list shorter by 1
				[FirstItem|_] = OriginalList,
				ShorterList = lists:delete(FirstItem, OriginalList),
				length(ShorterList) == length(OriginalList) - 1
			catch error:Error -> Error
			end)).

genRandomList(Command) ->
	case Command of
		ints -> lists:seq(1, 10);
		atoms -> [these, are, all, atoms, lol];
		mixed -> [{true, tuple}, {"hi", 2}, 
				  atom, <<1:1,0:1>>, -77]
	end.


%% Testing of lists:seq/3 based on this informal specification (from Erlang docs):
%%
%% Returns a sequence of integers which starts with 
%% From and contains the successive results 
%% of adding Incr to the previous element, 
%% until To has been reached or passed 
%% (in the latter case, To is not an element of the 
%% sequence). Incr defaults to 1.

%% Failure: 
%%   To<From-Incr and Incr is positive,
%%   To>From-Incr and Incr is negative,
%%   Incr==0 and From/=To.

%% The following equalities hold for all sequences:
%%   length(lists:seq(From, To, Incr)) == (To-From+Incr) div Incr

prop_seq3() ->
	?FORALL({From,To,Incr},gen_triple(),
			collect((abs(From) > 10) and (abs(To) > 10),
					
					% possible filtering of uninteresting test cases
					% ?IMPLIES(((Incr /= 0) and (From /= To)),
					
					% we can print additional info when failing
					% ?WHENFAIL(io:format("Generated sequence: ~w~n",[lists:seq(From,To,Incr))])
					
					try 
						% main property
						length(lists:seq(From, To, Incr)) == (To - From + Incr) div Incr
					catch
						% negative tests - we expect the function to fail!
						error:_ -> 
							((To > From - Incr) and (Incr < 0))
								or 
								((To < From - Incr) and (Incr > 0))
								or
								((Incr == 0) and (From /= To))
					end)).


gen_triple() -> 
	BigAbs = choose(-100,100),
	{BigAbs,BigAbs,BigAbs}.
