class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int ithPerson = 1;
        
        while(true) {
            long long strength = ithPerson*ithPerson;
            if(strength<=p) {
                p -= strength;
                ithPerson++;
            }
            else {
                break;
            }
        }
        
    return ithPerson-1;
    }
};
