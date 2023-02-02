# coder
class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        sentence1_a = sentence1.split(' ')
        sentence2_a = sentence2.split(' ')
        len_1_a = len(sentence1_a)
        len_2_a = len(sentence2_a)
        if (len_1_a > len_2_a):
            sentencemed_a = sentence2_a
            sentence2_a = sentence1_a
            sentence1_a = sentencemed_a
        len_1_a = len(sentence1_a)
        len_2_a = len(sentence2_a)
        i_1 = 0
        i_2 = 0
        limit = 0
        limit_bool = 1
        match_ = 0
        while (i_1 < len_1_a):
            if (sentence1_a[i_1] == sentence2_a[i_2]):
                i_1 += 1
                i_2 += 1
                match_ += 1
            else:
                break
        i_1_r = len_1_a-1
        i_2_r = len_2_a-1
        while (i_1_r >= i_1):
            if (sentence1_a[i_1_r] == sentence2_a[i_2_r]):
                i_1_r -= 1
                i_2_r -= 1
                match_ += 1
            else:
                break
        if (match_ != len_1_a):
            return False
        return True
