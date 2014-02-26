%% @author dani
%% @doc @todo Add description to qcdani.


-module(qcdemo2).
-include_lib("eqc/include/eqc.hrl").
-compile(export_all).

%% Provided example
%% ----------------------------------------
%% Code-example, fixed testing for negative values
prop_seq2() -> ?FORALL(
			   {From,To}, {int(),int()},
			   collect({From, To}, 
					   try 
						   List = lists:seq(From,To),
						   length(List) == (To - From + 1)
					   catch
						   error:_ -> 
							   NegList = lists:seq(To, From),
							   -length(NegList) == To - From - 1
					   %%(To-From+1)  0
					   end)).

%% Testing lists:seq/3 example 1
%% ----------------------------------------
%% This is the first testing example. Testing for 
%% inc being positive and incs being negative separately.
%% It also avoids extreme cases, i.e inc being 0.
%% This is done by generating the 3 arguments randomly
%% within certain ranges

prop_lists_seq1() ->
	prop_seq1_helper(pos),
	prop_seq1_helper(neg).

prop_seq1_helper(Command) ->
	?FORALL(
	{From, To, Inc}, gen_ints(Command),
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

gen_ints(Command) ->
	case Command of
		pos -> gen_positive();
		neg -> gen_negative()
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

%% Testing lists:seq/3 example 2
%% ----------------------------------------
%% This is the second example following the provided
%% examples. It verifies the extreme values in the catch

prop_lists_seq2() ->
	?FORALL(
	{From, To, Inc}, {int(), int(), int()},
	collect(
	  	(abs(From) > 0) 
		   and (abs(To) > 1) 
		   and (abs(Inc) > 0), 
			try
				List = lists:seq(From, To, Inc),
				[H|_] = List,
				
				%%Test1
				From == H,
				%%Test2
				is_inc(List, Inc) == true
			catch error:_ -> 
				(Inc == 0)
				or
				((From > To) and (Inc >= 0))
				or
				((To > From) and (Inc =< 0))

			end)).

%% Helper method for testing increment
is_inc([_|[]], _) ->
	true;
is_inc([H, H2|T], Inc) ->
	%% 	io:format("H: ~p, H2: ~p, Inc: ~p~n", [H, H2, Inc]),
	case H2 - H of
		Inc -> is_inc([H2|T], Inc)
	end.


%% Testing lists by removing values
%% ----------------------------------------
%% I test 3 different lists, integers, atoms
%% and a mixed lists of tuples, binaries, atoms and
%% integers in the mixed one. I was not sure if I 
%% could supply with only one mixed example so provided
%% multiple list test

prop_lists() ->
	prop_2_help(ints),
	prop_2_help(atoms),
	prop_2_help(mixed).

gen_list(Command) ->
	case Command of
		ints -> lists:seq(1, 10);
		atoms -> [these, are, all, atoms, lol];
		mixed -> [{true, tuple}, {"hi", 2}, 
				  atom, <<1:1,0:1>>, -77]
	end.

prop_2_help(Command) ->
	?FORALL(
	{OriginalList}, {gen_list(Command)},
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