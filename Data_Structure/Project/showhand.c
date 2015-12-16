//ShowHands
//15.11.29
//author: chuanlu

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//struct of card: suit and rank;
typedef struct card
{
	//suit: spades = 3; hearts = 2; clubs = 1; diamonds = 0;
	//rank: eight = 8; nine = 9; ten = 10; Jack = 11; Queen = 12; King = 13; Ice = 14;
	int suit;
	int rank;
}card;

//struct of card type: type, largest rank and largest suit;
typedef struct type
{
	int type; 
	int rank;
	int suit;
}type;

// const card S8 = {3, 8};
// const card S9 = {3, 9};
// const card S10 = {3, 10};
// const card S11 = {3, 11};
// const card S12 = {3, 12};
// const card S13 = {3, 13};
// const card S14 = {3, 14};
// const card H8 = {2, 8};
// const card H9 = {2, 9};
// const card H10 = {2, 10};
// const card H11 = {2, 11};
// const card H12 = {2, 12};
// const card H13 = {2, 13};
// const card H14 = {2, 14};
// const card C8 = {1, 8};
// const card C9 = {1, 9};
// const card C10 = {1, 10};
// const card C11 = {1, 11};
// const card C12 = {1, 12};
// const card C13 = {1, 13};
// const card C14 = {1, 14};
// const card D8 = {0, 8};
// const card D9 = {0, 9};
// const card D10 = {0, 10};
// const card D11 = {0, 11};
// const card D12 = {0, 12};
// const card D13 = {0, 13};
// const card D14 = {0, 14};

// card all_cards[28] = {S8, S9, S10, S11, S12, S13, S14,
// 					H8, H9, H10, H11, H12, H13, H14,
// 					C8, C9, C10, C11, C12, C13, C14,
// 					D8, D9, D10, D11, D12, D13, D14};


//sort cards in order of rank

//sort hand of card in natural order
void sort_card(card *hand[])
{
	//bubble_sort
	int len = 5, i = 0, j;
	//sort in order of rank
	for(i; i < len - 1; i++)
	{
		for(j = len - 1; j >= i + 1; j--)
		{
			if(hand[j]->rank > hand[j-1]->rank)
			{
				card *temp;
				temp = hand[j];
				hand[j] = hand[j - 1];
				hand[j - 1] = temp;
			}
		}
	}
	//sort in order of suit, when ranks are the same
	for(i = 0; i < len - 1; i++)
	{
		for(j = len - 1; j >= i + 1; j--)
		{
			if(hand[j]->rank == hand[i-1]->rank)
			{
				if(hand[j]->suit > hand[j-1]->suit)
				{
					card *temp;
					temp = hand[j];
					hand[j] = hand[j-1];
					hand[j-1] = temp;
				}
			}
		}
	}
}

// Judge if two cards are the same
int is_same_card(card *list)
{
	int len = sizeof(list)/sizeof(card);
	int i = 0;
	for(i = 0; i < len - 1; i++)
	{
		if(list[i].rank != list[i+1].rank || list[i].suit != list[i+1].suit)
			return 0;
	}
	return 1;
}

// Judge if two cards has the same suit
int is_same_suit(card hand[])
{
	int suit = hand[0].suit;
	int i;
	for(i = 1; i < 5; i++)
	{
		if(hand[i].suit != suit)
			return 0;
	}
	return 1;
}


// Judge if cards in hand are in the straight type
int is_straight(card hand[], int* rank, int* suit)
{
	int nrank = hand[4].rank;
	int i;
	for(i = 0; i < 5; i++)
	{
		if(hand[i].rank != nrank + i - 4)
		{
			*rank = -1;
			*suit = -1;
			return 0;
		}
	}
	*rank = nrank;
	*suit = hand[4].suit;
	return 1;
}

// Judge if cards in hand are in straight flush type
int is_straight_flush(card hand[], int *rank, int *suit)
{
	if(is_same_suit(hand) && is_straight(hand, rank, suit))
		return 1;
	else
		return 0;
}


// Judge if cards in hand are in four type
int is_four(card hand[], int *rank, int *suit)
{
	if(hand[0].rank == hand[3].rank)
	{
		*rank = hand[0].rank;
		*suit = hand[0].suit;
		return 1;
	}
	if(hand[1].rank == hand[4].rank)
	{
		*rank = hand[1].rank;
		*suit = hand[1].suit;
		return 1;
	}
	*rank = -1;
	*suit = -1;
	return 0;
}

// Judge if cards in hand are in full house type
int is_full_house(card hand[], int *rank, int *suit)
{
	card list1[3];
	list1[0] = hand[0];
	list1[1] = hand[1];
	list1[2] = hand[2];
	card list2[2];
	list2[0] = hand[3];
	list2[1] = hand[4];
	card list3[3];
	list3[0] = hand[2];
	list3[1] = hand[3];
	list3[2] = hand[4];
	card list4[2];
	list4[0] = hand[0];
	list4[1] = hand[1];
	if(is_same_card(list1) && is_same_card(list2))
	{
		*rank = hand[0].rank;
		*suit = hand[0].suit;
		return 1;
	}
	if(is_same_card(list3) && is_same_card(list4))
	{
		*rank = hand[2].rank;
		*suit = hand[2].suit;
		return 1;
	}
	*rank = -1;
	*suit = -1;
	return 0;
}

// Judge if cards in hand are in flush type
int is_flush(card hand[], int *rank, int *suit)
{
	if(is_same_suit(hand))
	{
		*rank = hand[0].rank;
		*suit = hand[0].rank;
		return 1;
	}
	return 0;
}


// Judge if cards in hand are in three type
int is_three(card hand[], int *rank, int *suit)
{
	card list1[3];
	list1[0] = hand[0];
	list1[1] = hand[1];
	list1[2] = hand[2];
	card list2[3];
	list2[0] = hand[1];
	list2[1] = hand[2];
	list2[2] = hand[3];
	card list3[3];
	list3[0] = hand[2];
	list3[1] = hand[3];
	list3[2] = hand[4];
	if(is_same_card(list1))
	{
		*rank = hand[0].rank;
		*suit = hand[0].suit;
		return 1;
	}
	if(is_same_card(list2))
	{
		*rank = hand[1].rank;
		*suit = hand[1].suit;
		return 1;
	}
	if(is_same_card(list3))
	{
		*rank = hand[2].rank;
		*suit = hand[2].suit;
		return 1;
	}
	*rank = -1;
	*suit = -1;
	return 0;
}

// Judge if cards in hand are in two pairs-type
int is_two_pairs(card hand[], int *rank, int *suit)
{
	if(hand[0].rank == hand[1].rank)
	{
		if(hand[2].rank == hand[3].rank || hand[3].rank == hand[4].rank)
		{
			*rank = hand[0].rank;
			*suit = hand[0].suit;
			return 1;
		}
	}
	if(hand[1].rank == hand[2].rank)
	{
		if(hand[3].rank == hand[4].rank)
		{
			*rank = hand[1].rank;
			*suit = hand[1].suit;
			return 1;
		}
	}
	*rank = -1;
	*suit = -1;
	return 0;
}


// Judge if cards in hand are in pair-type
int is_pair(card hand[], int *rank, int *suit)
{
	card list1[2];
	list1[0] = hand[0];
	list1[1] = hand[1];
	card list2[2];
	list2[0] = hand[1];
	list2[1] = hand[2];
	card list3[2];
	list3[0] = hand[2];
	list3[1] = hand[3];
	card list4[2];
	list4[0] = hand[3];
	list4[1] = hand[4];
	if(is_same_card(list1))
	{
		*rank = hand[0].rank;
		*suit = hand[0].suit;
		return 1;
	}
	if(is_same_card(list2))
	{
		*rank = hand[1].rank;
		*suit = hand[1].suit;
		return 1;
	}
	if(is_same_card(list3))
	{
		*rank = hand[2].rank;
		*suit = hand[2].suit;
		return 1;
	}
	if(is_same_card(list4))
	{
		*rank = hand[3].rank;
		*suit = hand[3].suit;
		return 1;
	}
	*rank = -1;
	*suit = -1;
	return 0;
}

// Judge if cards in hand are in high-type
int is_high(card hand[], int *rank, int*suit)
{
	*rank = hand[0].rank;
	*suit = hand[0].suit;
	return 1;
}


// get type of cards in hand
int get_type(card hand[], int *rank, int *suit)
{
	if(is_straight_flush(hand, rank, suit))
		return 8;
	if(is_four(hand, rank, suit))
		return 7;
	if(is_full_house(hand, rank, suit))
		return 6;
	if(is_flush(hand, rank, suit))
		return 5;
	if(is_straight(hand, rank, suit))
		return 4;
	if(is_three(hand, rank, suit))
		return 3;
	if(is_two_pairs(hand, rank, suit))
		return 2;
	if(is_pair(hand, rank, suit))
		return 1;
	if (is_high(hand, rank, suit))
		return 0;
	else
		return 0;
}

//compare two different types
int cmp_type(type Type1, type Type2)
{
	if(Type1.type == Type2.type)
	{
		if(Type1.rank == Type2.rank)
		{
			if(Type1.suit > Type2.suit)
				return 1;
			else
				return 0;
		}
		else
		{
			if(Type1.rank > Type2.rank)
				return 1;
			else
				return 0;
		}
	}
	else
	{
		if(Type1.type > Type2.type)
			return 1;
		else
			return 0;
	}
}

// get left cards with the 9 cards given
card* get_left_cards(card hand_1[], card hand_2[])
{
	card *left_cards;
	left_cards = (card*)malloc(19*sizeof(card));
	int i, j, k;
	int count = 0;
	for(i = 0; i <= 3; i++)
	{
		for(j = 2; j <= 14; j++)
		{
			int flag = 1;
			for(k = 0; k <= 3; k++)
			{
				if(hand_1[k].rank == j && hand_1[k].suit == i)
					flag = 0;
			}
			for(k = 0; k <= 4; k++)
			{
				if(hand_2[k].rank == j && hand_2[k].suit == i)
					flag = 0;
			}
			if(flag == 1)
			{
				card left = {i, j};
				left_cards[count] = left;
				count++;
			}
		}
	}
	return left_cards;
}

//calculate the prob. of person2's winning
float count_winning_prob(card hand_1_input[], card hand_2_input[])
{
	int win = 0, lose = 0;
	int *suit_1 = malloc(sizeof(int)), *suit_2 = malloc(sizeof(int)), *rank_1 = malloc(sizeof(int)), *rank_2 = malloc(sizeof(int));
	int type_2 = get_type(hand_2_input, rank_2, suit_2);
	type final_type2 = {type_2, *rank_2, *suit_2};
	card *left_cards = get_left_cards(hand_1_input, hand_2_input);
	int i = 0;
	for(i = 0; i < 19; i++)
	{
		card *final_hand1;
		int j = 0;
		final_hand1 = (card*)malloc(5*sizeof(card));
		for(j = 0; j < 4; j++)
		{
			final_hand1[j] = hand_1_input[j];
		}
		final_hand1[4] = left_cards[i];
		int type_1 = get_type(final_hand1, rank_1, suit_1);
		type final_type1 = {type_1, *rank_1, *suit_1};
		int result = cmp_type(final_type1, final_type2);
		if(result == 1)
			lose++;
		else
			win++;
	}
	float prob = (float)win / lose;
	return prob;
}

int main()
{
	FILE *fp;
	fp = fopen("/mnt/hgfs/GitHub/Learning/Data_Structure/Project/card.txt", "rb");

 	// fp = fopen("F:\\Documents\\GitHub\\Learning\\Data_Structure\\Project\\cards.txt", "r");
	card *hand_1, *hand_2;
	hand_1 = (card*)malloc(4*sizeof(card));
	hand_2 = (card*)malloc(5*sizeof(card));
	int i = 0;
	for(i = 0; i < 4; i++)
	{
        char *suit_tmp, *rank_tmp;
		suit_tmp = malloc(10*sizeof(char));
		rank_tmp = malloc(10*sizeof(char));
		fscanf(fp, "%s", suit_tmp);
		fscanf(fp, "%s", rank_tmp);
		int suit, rank;
		switch(suit_tmp[0])
		{
			case 's':
				suit = 3;
				break;
			case 'h':
				suit = 2;
				break;
			case 'c':
				suit = 1;
				break;
			case 'd':
				suit = 0;
				break;
			default:
				break;
		}
		switch(rank_tmp[0])
		{
			case '8':
				rank = 8;
				break;
			case '9':
				rank = 9;
				break;
			case '1':
				rank = 10;
				break;
			case 'J':
				rank = 11;
				break;
			case 'Q':
				rank = 12;
				break;
			case 'K':
				rank = 13;
				break;
			case 'A':
				rank = 14;
				break;
			default:
				break;
		}
		hand_1[i].suit = suit;
		hand_1[i].rank = rank;
	}
	for(i = 0; i < 5; i++)
	{
		char *suit_tmp = 0, *rank_tmp = 0;
		suit_tmp = (char*)malloc(100*sizeof(char));
		rank_tmp = (char*)malloc(100*sizeof(char));
		fscanf(fp, "%s", suit_tmp);
		fscanf(fp, "%s", rank_tmp);
		int suit, rank;
		switch(suit_tmp[0])
		{
			case 's':
				suit = 3;
				break;
			case 'h':
				suit = 2;
				break;
			case 'c':
				suit = 1;
				break;
			case 'd':
				suit = 0;
				break;
			default:
				break;
		}
		switch(rank_tmp[0])
		{
			case '8':
				rank = 8;
				break;
			case '9':
				rank = 9;
				break;
			case '1':
				rank = 10;
				break;
			case 'J':
				rank = 11;
				break;
			case 'Q':
				rank = 12;
				break;
			case 'K':
				rank = 13;
				break;
			case 'A':
				rank = 14;
				break;
			default:
				break;
		}
		hand_2[i].suit = suit;
		hand_2[i].rank = rank;
	}
	float prob;
	prob = count_winning_prob(hand_1, hand_2);
	FILE *fpout;
 	// fpout = fopen("F:\\Documents\\GitHub\\Learning\\Data_Structure\\Project\\answer.txt", "w");
	fpout = fopen("/mnt/hgfs/GitHub/Learning/Data_Structure/Project/answer.txt", "wb");
	if(prob >= 0.5)
		fprintf(fpout, "%s", "YES");
	else
        fprintf(fpout, "%s", "NO");
}
