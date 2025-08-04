class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int firstBasket = -1; // for fruit stored in 1st basket
        int secondBasket = -1; // for fruit stored in secod basket

        int ans = -1; // final ans to return

        int countA = 0; //  no of fruits in firstbasket
        int countB = 0; // no of fruits in second basket

        for(int i = 0;i<fruits.size();i++)
        {
            int fruit = fruits[i]; // current fruit

            if(firstBasket == -1){ // first Basket is empty
                firstBasket = fruit;
                countA++;
            }
            else if(firstBasket == fruit){ // fruit found in first basket
                countA++;
            }
            else if(secondBasket == -1){ // second basket is empty
                secondBasket = fruit;
                countB++;
            }
            else if(secondBasket == fruit){ // fruit found in second basket
                countB++;
            }
            else if(fruits[i-1] == firstBasket){
                secondBasket = fruit;
                countB = 1;
                int j = i-1;
                countA = 0;
                while(j >= 0 &&fruits[j] == firstBasket){
                    countA++;
                    j--;
                }
            }
            else if(fruits[i-1] == secondBasket){
                firstBasket = fruit;
                countA = 1;
                int j = i-1;
                countB = 0;
                while(j >= 0 &&fruits[j] == secondBasket){
                    countB++;
                    j--;
                }
            }


            ans = max(ans,countA + countB);

        }

        return ans;
    }
};