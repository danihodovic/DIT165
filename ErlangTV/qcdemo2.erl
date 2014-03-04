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


%% Testing lists:seq/3 example 2
%% ----------------------------------------
%% This is the second example following the provided
%% examples. It verifies the extreme values in the catch

expected_fail(From, To, Inc) ->
	(Inc == 0)
		or
		((From > To) and (Inc >= 0))
		or
		((To > From) and (Inc =< 0)).

prop_list_seq() ->
	?FORALL(
	{From, To, Inc}, {int(), int(), int()},
	collect(
	  expected_fail(From, To, Inc), 
	  try
		  List = lists:seq(From, To, Inc),
		  [H|_] = List,
		  
		  %%Test1
		  From == H,
		  %%Test2
		  is_inc(List, Inc)
	  catch error:_ -> 
				expected_fail(From, To, Inc)
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
gen_random_list() ->
	list(gen_random_item()).

gen_random_item() ->
	oneof([int(), binary(), char(), bitstring(), bool(),
		   nat(), largeint()]).

prop_list_1() ->
	?FORALL(
	{OriginalList}, {gen_random_list()},
	collect(OriginalList /= [], 
			try
				%% Test1 - Remove nonexist item list is unchanged
				MutatedList = lists:delete("test", OriginalList),
				MutatedList == OriginalList,
				
				%% Test2 - Remove exist item, list shorter by 1
				[FirstItem|_] = OriginalList,
				ShorterList = lists:delete(FirstItem, OriginalList),
				length(ShorterList) == length(OriginalList) - 1
			
			catch error:_Error -> 
					  OriginalList == []
			end)).

%% Testing adding and removing random item
%% ----------------------------------------

item_exists([H|_T], H) ->
	true;
item_exists([H|T], Item) ->
	%io:format("LOOOOOOHead: ~p, Item: ~p~n", [H, Item]),
	item_exists(T, Item);
item_exists([], _) ->
	false.

prop_list_2() ->
	?FORALL(
	{OriginalList, Randomitem}, {gen_random_list(), gen_random_item()},
	collect(item_exists(OriginalList, Randomitem), 
			try
				AddedList = OriginalList ++ [Randomitem],
				OriginalList == AddedList -- [Randomitem]
			catch error:Error -> 
				Error
			%item_exists(OriginalList, Randomitem)
			end)).

%% Testing calendar:last_day_of_the_month/2
%% ----------------------------------------

check_leap_year(Year, Day) ->
	case calendar:is_leap_year(Year) of
		 true ->
			Day == 29;
		false -> Day == 28
	end.
prop_date() ->
	?FORALL(
	{Year, Month}, {choose(0, 10000), choose(1, 12)},
	try
		Day = calendar:last_day_of_the_month(Year, Month),
		case Month of
			1 -> Day == 31;
			2 -> check_leap_year(Year, Day);
			3 -> Day == 31;
			4 -> Day == 30;
			5 -> Day == 31;
			6 -> Day == 30;	
			7 -> Day == 31;
			8 -> Day == 31;
			9 -> Day == 30;
			10 -> Day == 31;
			11 -> Day == 30;
			12 -> Day == 31
		end
	catch error:Error -> 
		Error
	end).