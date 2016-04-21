#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <cmath>
#include <sstream>


using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};



int singleNumber(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());

    return 0;

}
bool checkValid(string s ){

    int count1 = 0;
    int count2 = 0;
    bool result = true;
    for(unsigned long i = 0 ; i < s.length(); i++){
        if(s[i] == '('){
            count1 ++;
        }else{
            count2 ++;
        }

        if(count2 > count1){
            result = false;
            return false;
        }
    }

    return true;
}
vector<string> generateParenthesis(int n) {
    vector<string> v;

    string s = "";
    for(int i = 0; i < n; i++ ){
        s = s + "(";
    }
    for(int i = 0; i < n; i++ ){
        s = s + ")";
    }

    do{
        if(s[0] == ')' || s[s.length() -1 ] == '('){
            continue;
        }else{
            bool t = true;
            t = checkValid(s);
            if(t==true){
                v.push_back(s);
            }
            //cout << s << endl;
        }
    }while(next_permutation(s.begin(),s.end()));


    for(unsigned long i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    return v;

}

struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
};

void travel(TreeLinkNode *root,TreeLinkNode *next, bool isleft, bool beenToLeft){


    if(isleft){
        root->left->next = root -> right;
        root-> right -> next = next -> left;
        beenToLeft = true;
        if(root -> left -> left!= NULL){
            travel(root->left,root->left->next,isleft, beenToLeft);
            travel(root->right,root-> right -> next,0, beenToLeft);
        }
    }
    else{

        root->left ->next = root-> right;
        if(beenToLeft){
            root -> right -> next = next -> left;
        }
        if(root->left -> left != NULL){
            travel(root->left, root->left->next, 1, beenToLeft);
            travel(root->right, root->right->next,0,beenToLeft);
        }
        
       
    }

}
void connect(TreeLinkNode *root) {
    if(root == NULL) return;
    if(root -> left != NULL){
        root -> left -> next = root -> right;
        if(root -> left -> left != NULL){
            travel(root -> left, root->left -> next, 1, 1);
            travel(root -> right, root->right->next,0,0);
        }

    }
}



int maxSubArray(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int> > v(length, vector<int>(length)); 
    int max = 0;
    for(int i = 0; i < length; i++){
        if(nums[i] > max){
            max = nums[i];
        }
    }

    for(int i = 0; i < length; i++){
        v[0][i] = max;
    }

 //   cout << "max: " << max << endl;

    int t_max = max;
    for(int i = 1; i < length;i++){
       // t_max = v[i-1][length-1];
        for(int j = i; j < length; j++){
            int tmp = 0;
            int count = i + 1;
            int j2 = j;
           

                while(count > 0){
                    tmp = tmp + nums[j2];
                    count --;
                    j2 --;
                }

                if(tmp > t_max){
                    v[i][j] = tmp;
                    t_max = tmp;
                }else{
                    
                    v[i][j] = t_max;
                }
            
        }
    }
/*
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            cout << v[i][j] << " " ;
        }
        cout << endl;
    }

*/


    cout <<  v[length-1][length-1] << endl;

    return v[length-1][length-1];

}


int uniquePaths(int m, int n) {
        
    vector <vector<int> > v(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        v[i][0] = 1;
    }
    for(int i = 0; i < n; i++){
        v[0][i] = 1;
    }

    for(int i = 1; i < m ; i++ ){
        for (int j = 1; j < n ; j++ ){
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }


    return v[m-1][n-1];
}


int maxProfit(vector<int>& prices) {
/*
    vector<int> v(prices.size(), 0);

    int max = 0;
    for(unsigned long i = 0; i < prices.size(); i++){
        for(int j = i; j >= 0 ; j --){

            int tmp = prices[i] - prices[j];
            if(tmp > max){
                max = tmp;
            } 

        }
    }
    cout << max << endl;

    return max;
*/

/*
    if(prices.size() == 0){
        return 0;
    }
    int max = 0;
    for(unsigned long i = 0 ; i < prices.size() - 1; i++){
        for(unsigned long j = i + 1; j  <prices.size();j++ ){
            int tmp_max = prices[j] - prices[i];
            if(tmp_max > max ){
                max = tmp_max;
            }
        }
    } 

    return max;
*/


    if(prices.size() == 0){
        return 0;
    }
    int max = 0;
    int min = prices[0];

    for(unsigned long i =1; i < prices.size(); i++ ){
        if(min > prices[i] ){
            min = prices[i];
        }
        if(max < prices[i] - min){
            max = prices[i] - min;
        }

    }
    return max;
}

void helper(vector<vector<int> > &result, vector<int> &v, int start, int k, int n){

    if(k == 0 && n == 0){
        result.push_back(v);
        return;
    }
    for (int i = start; i < 10; i ++ ){
        v.push_back(i);
        helper(result, v, start + 1,k -1  ,n - i);
        v.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
        
    vector<vector<int> > result;

    vector<int> v; 
    helper(result, v, 1, k,n);
    return result;

}

vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result; 
        sort(nums.begin(), nums.end());
        vector<int> v = nums;
        do{ 
            v =nums;
            result.push_back(v);

        }while(next_permutation(nums.begin(),nums.end()));
       
         return result;

}

void helper2(vector<vector<int> > &result, queue<int> &q, int n, int start, int end){
    if(q.empty()){
        return;
    }
           
    for(int i = start; i <= end ; i++ ){


        result[start][i] = q.front();

        q.pop();
    }



    for(int i = start+1; i <= end; i++){
        result[i][end] = q.front();

        q.pop();
    }


    for(int i = end - 1; i >=start; i-- ){
        result[end][i] = q.front();

        q.pop(); 
    }

    for(int i = end -1 ;  i > start;i-- ){
        result[i][start] = q.front();
        q.pop();
    }

    helper2(result,q, n - 2,start+1, end -1);


}
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int> > result(n, vector<int>(n));  
    queue<int> q;
     for(int i = 1; i <=n*n; i++){
        q.push(i);
    } 

    helper2(result,q, n , 0, n-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return result;
}


int minPathSum(vector<vector<int>>& grid) {
    
    for(unsigned long i = 1; i < grid[0].size(); i++){
        grid[0][i] = grid[0][i-1] + grid[0][i];
    }

    for(unsigned long i = 1; i < grid.size(); i++){
        grid[i][0] = grid[i-1][0] + grid[i][0];
    }
    for(unsigned long i = 1; i < grid.size();i++){
        for(unsigned long j = 1; j < grid[0].size();j++){

            if(grid[i][j-1] > grid[i-1][j]){
                grid[i][j] = grid[i][j] + grid[i-1][j];
            }else{
                grid[i][j] = grid[i][j] + grid[i][j-1];
            }
        }
    }

    return grid[grid.size() - 1][grid[0].size() -1];
}

void sortColors(vector<int>& nums) {
        
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    vector<int> v;
    for(unsigned long i = 0; i < nums.size(); i++){

        if(nums[i] == 0){
            count_0 ++;
        }else if(nums[i] == 1){
            count_1 ++;
        }else{
            count_2 ++;
        }
    }
    
    while(count_0 != 0){
        v.push_back(0);
        count_0--;

    }
    while(count_1 != 0){
        v.push_back(1);
        count_1--;

    }
    while(count_2 != 0){
        v.push_back(2);
        count_2--;

    }

    for(unsigned long i =0 ; i < v.size(); i++){
        nums[i] = v[i];
    }
    return;

}



void rotate(vector<vector<int>>& matrix) {
    vector<vector<int> > v(matrix.size(), vector<int>(matrix.size()));
    int tmp = 0;
    for(int i = matrix[0].size()-1; i >= 0; i--){
        for(unsigned long j = 0; j < matrix.size(); j++){
            v[j][i] = matrix[tmp][j];
        }
        tmp++;
    }
   
    for(unsigned long i = 0; i < v.size(); i++){
        for(unsigned long j = 0; j < v[0].size();j++ ){
            matrix[i][j] = v[i][j];
        }
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++ ){
        for(int j = 0; j < n; j++){
            
        }
    }

    return TRUE;

}
 
int main(){

    cout << "test " ;

    return 0;

}


