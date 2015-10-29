#include <stdio.h>
#include <string.h>
#include "word_manage_p.h"
/*******************************
 *ある単語の出現回数を返す
 *******************************/

int get_word_count(char *word)
{
  int left = 0;
  int right = num_of_word -1;
  int mid;
  int result;

  while(left <= right){
    mid = (left + ringt ) / 2;
    result = strcmp(word_array[mid].name, word);
    if(result < 0){
      left = mid + 1;
    }else if (result > 0){
      right = mid - 1;
    }else {
      return word_array[mid].count;
    }
  }
  return 0;
}