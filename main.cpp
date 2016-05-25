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
#include <climits>


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



int integerBreak(int n) {
    if(n == 2 )  return 1;
    if(n == 3 )  return 2;
    if(n == 4)  return 4;
    if(n == 5 )  return 6;
    if(n == 6 )  return 9;
    return 3*integerBreak(n-3);
}


bool searchMatrix(vector<vector<int> >& matrix, int target) {
    
    unsigned long i = 0;
    int j = matrix[0].size() - 1;    

    while(i < matrix.size() && j>= 0){
        if(matrix[i][j]  == target){
            return true;
        }

        if(matrix[i][j] < target){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

struct TreeNode {
   int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helperRightSideView(TreeNode * root, unsigned long level, vector<int> &result){

    if(root == NULL) return;
    if( result.size() < level ) result.push_back(root->val);
    helperRightSideView(root -> right, level+1, result);
    helperRightSideView(root -> left, level+1, result);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;

    helperRightSideView(root,1,result);

    return result;
}




string reverseString(string s) {
    int length = s.length();
    bool even = true;
    if(length%2 ){
        even = false;
    }
    
    if(even){   
        int end = length; 
        for(int i = 0; i < length/2; i++){
            char tmp = s[i];
            s[i] = s[end-1];
            s[end-1] = tmp;
            end --;
        }
        return s;
    }else{
        int end = length;
        for(int i = 0; i < (length - 1)/2; i++){
            char tmp = s[i];
            s[i] = s[end-1];
            s[end-1] = tmp;
            end --;
        }
        return s;
    }
}



void invertTree_helper(TreeNode * root){
    if(root -> left != NULL && root ->right != NULL){

        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;
    
        root -> left = root -> right;
        root -> right = tmp;
    }
    if(root -> left !=NULL && root -> right == NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = NULL;
        root -> right = tmp;
    }else if(root -> right !=NULL && root -> left == NULL){
        TreeNode *tmp = new TreeNode(root->right->val);
        tmp -> left = root -> right -> left;
        tmp -> right = root -> right -> right;

        root -> left = tmp;
        root -> right = NULL;
    }

    if(root -> left != NULL){
       invertTree_helper(root -> left); 
    }
    if(root -> right != NULL){
        invertTree_helper(root -> right);
    }
    return;
}

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){
        return root;
    }

    if(root -> left != NULL && root ->right != NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = root -> right;
        root -> right = tmp;
    }

    if(root -> left !=NULL && root -> right == NULL){
        TreeNode *tmp = new TreeNode(root->left->val);
        tmp -> left = root -> left -> left;
        tmp -> right = root -> left -> right;

        root -> left = NULL;
        root -> right = tmp;
    }else if(root -> right !=NULL && root -> left == NULL){
        TreeNode *tmp = new TreeNode(root->right->val);
         tmp -> left = root -> right -> left;
        tmp -> right = root -> right -> right;

        root -> left = tmp;
        root -> right = NULL;
    }
    
    if(root -> left != NULL){
       invertTree_helper(root -> left); 
    }
    if(root -> right != NULL){
        invertTree_helper(root -> right);
    }
    return root;
}


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1;
    unordered_set<int> s2;
    
    for(unsigned long i = 0; i < nums1.size(); i++){
        s1.insert(nums1[i]);
    }
    for(unsigned long i = 0; i < nums2.size(); i++){
        s2.insert(nums2[i]);
    } 
        vector<int> result;
    for(auto i = s2.begin(); i != s2.end(); i++){
        if(s1.find(*i) != s1.end()){
            result.push_back(*i);

        }
    }


    return result;
}


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int ,int> m;
    for(unsigned long i = 0; i < nums1.size(); i++){
        if(m.find(nums1[i] )== m.end()){
            m[nums1[i]] = 1;
        }else{
            m[nums1[i]]++;
        }
    }

    for(unsigned long i = 0; i< nums2.size();i++){
        if(m.find(nums2[i]) != m.end() && m[nums2[i]] != 0){
            result.push_back(nums2[i]);
            m[nums2[i]]--;
        }
    }
    return result;

}

int lengthOfLIS(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    if(nums.size() == 1 ) return 1;
    if(nums.size() == 0) return 0;
    int min = 0;
    unsigned long i;
    for(i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]){
            min = nums[i-1];
            break;
        }
    }
    cout << "min: " << min << endl; 

    for(unsigned long j = i ; j<nums.size(); j++){

        if(nums[j] > min ){
            result[j] = result[j-1] + 1;
            min = nums[j];
        }else{
            result[j] = result[j-1];
        }

    }
     for(unsigned long k = 0; k < result.size(); k++){
        cout << result[k] <<  " ";

    }
    cout << endl;
    sort(result.begin(), result.end());

    for(unsigned long k = 0; k < result.size(); k++){
        cout << result[k] <<  " ";

    }
    cout << endl;

    return result[result.size()-1];
}

bool binary_search(unsigned long m, unsigned long beginning, unsigned long end, vector<vector<int>> &matrix,  int target, bool &result){
    
    if(end < beginning) return false;
    else if(end == beginning){
        if(matrix[m][beginning] == target){
            result = true;
            return true;
        } 
        else return false;
    }
    int mid = (end+beginning+1)/2;
    cout << "mid: " << mid << endl;
    cout << "8: " << matrix[m][mid] << "99: " << target << endl;
    if(matrix[m][mid] == target){
      //  cout << "10 ---- " << endl;
        result = true;
        return true;
     //   cout << "11 ------  " << endl;
    }
    else if(matrix[m][mid] < target){
      //  cout << "13 ------  " << endl;

        beginning = mid;
        binary_search(m,beginning,end,matrix,target,result);
    }
    else if(matrix[m][mid] > target){

        end = mid -1;
        binary_search(m,beginning,end,matrix,target,result);
    }
    return false;
}

bool searchMatrix_2nd(vector<vector<int>>& matrix, int target) {
    // 先确定哪一行 再做binary search 
    int m = -1; // 哪一个row 的 index
    bool exist = false;
    cout << "1111 " << endl; 
    for(unsigned long i = 0; i < matrix.size();i++){
        if(matrix[i][0] == target){
                cout << "2222 " << endl; 

            return true;
        }
        else if(matrix[i][0] < target){
                cout << "3333 " << endl; 
            exist = true;
            m = i;
        }

    }
        cout << "44444 " << endl; 
    if(exist == false) return false;
    cout << "5555 " << endl;
    cout << "m: " << m << endl;
    cout << matrix[m][matrix[0].size()-1] << endl;
    cout << "target: " << target << endl;
    if(matrix[m][matrix[0].size()-1] == target){
            cout << "6666 " << endl;

        return true;
    }
    else if(matrix[m][matrix[0].size()-1] < target){
            cout << "7777 " << endl;

        return false;
    }


    // 确定可能在 index 为 m 的这一行里 之后做 binary search
    unsigned long n = matrix[0].size()-1;

    cout << "m: " << m << endl;
    cout << "n: " << n << endl;
    bool result = false;
    binary_search(m,0,n,matrix,target,result);
    return result;
}

bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX;
    int b = INT_MAX;
    for(int x : nums){
        if(x <= a){
            a = x;
        }
        else if( x <= b){
            b = x;
        }
        else return true;
    }
    return false;
}

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int size = nums.size();
    return nums[size-k];
            
}

void setZeroes(vector<vector<int>>& matrix) {

    unordered_set<int> column;
    unordered_set<int> row;

    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                row.insert(i);
                column.insert(j);
            }
        }
    }

    for(auto itr = row.begin(); itr != row.end(); itr ++){
        for(int j = 0; j < n ; j++){
            matrix[*itr][j] = 0;
        }
    }

    for(auto itr = column.begin(); itr != column.end(); itr ++){
        for(int i = 0; i < m ; i++){
            matrix[i][*itr] = 0;
        }
    }

    return;

}

int findPeakElement(vector<int>& nums) {

    if(nums.size() == 1 ) return 0;
    int index = 0;
    for(unsigned long i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i-1]){
            index = i;
        }else{
            break;
        }
    }
    return index;
}

int sumNumbers_helper(TreeNode *root, int result){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return result*10 + root -> val;
    }

    return sumNumbers_helper(root->left, result*10 + root->val) + sumNumbers_helper(root->right,result* 10 + root->val);

}
int sumNumbers(TreeNode* root) {
    int result = sumNumbers_helper(root, 0);
    return result;

}

int main(){
   
    vector<int> nums = {5,2,3,4,5,4};
    
    cout << findPeakElement(nums)<< endl;



    return 0;
}


