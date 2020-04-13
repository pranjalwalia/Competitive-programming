/*

    Node based seg tree to calculate max sum segments in the tree by 
    storing corresponding suffix and prefix sums

    zero based queries on the segment tree

	 int l = 5, r = 8; 
	 cout << query(a, 0, 0, n - 1, l - 1, r - 1).maxsum; 

	 int index = 1; 
	 int value = 10; 
	 update(a, 0, 0, n - 1, index - 1, value);

*/
#include <bits/stdc++.h> 
using namespace std; 

struct node { 
	int sum, prefixsum, suffixsum, maxsum; 
};

const int N=10001;
int a[N];
node tree[4 * N]; 

void build(int arr[], int ss, int se, int si) 
{ 
	if (ss == se) { 
		tree[si].sum = arr[ss]; 
		tree[si].prefixsum = arr[ss]; 
		tree[si].suffixsum = arr[ss]; 
		tree[si].maxsum = arr[ss]; 
	} 
	else { 
		int mid = (ss + se) / 2; 
		
		build(arr, ss, mid, 2 * si + 1); 
		
		build(arr, mid + 1, se, 2 * si + 2); 

		// parent node's sum is the summation 
		// of left and right child 
		tree[si].sum = tree[2 * si + 1].sum + 
						tree[2 * si + 2].sum; 

		// parent node's prefix sum will be equivalent 
		// to maximum of left child's prefix sum or left 
		// child sum + right child prefix sum. 
		tree[si].prefixsum = 
					max(tree[2 * si + 1].prefixsum, 
					tree[2 * si + 1].sum + 
					tree[2 * si + 2].prefixsum); 

		// parent node's suffix sum will be equal to right 
		// child suffix sum or right child sum + suffix 
		// sum of left child 
		tree[si].suffixsum = 
					max(tree[2 * si + 2].suffixsum, 
					tree[2 * si + 2].sum + 
					tree[2 * si + 1].suffixsum); 

		// maxum will be the maximum of prefix, suffix of 
		// parent or maximum of left child or right child 
		// and summation of left child's suffix and right 
		// child's prefix. 
		tree[si].maxsum = 
					max(tree[si].prefixsum, 
					max(tree[si].suffixsum, 
					max(tree[2 * si + 1].maxsum, 
					max(tree[2 * si + 2].maxsum, 
					tree[2 * si + 1].suffixsum + 
					tree[2 * si + 2].prefixsum)
                    )
                )
            ); 
	} 
} 

void update(int arr[], int si, int ss, int se, 
			int idx, int value) 
{   
    arr[si] = value;

	if (ss == se) { 
		tree[si].sum = value; 
		tree[si].prefixsum = value; 
		tree[si].suffixsum = value; 
		tree[si].maxsum = value; 
	} 
	else { 
		int mid = (ss + se) / 2; 

		// if node to be updated is in left subtree 
		if (idx <= mid) 
			update(arr, 2 * si + 1, ss, mid, idx, value); 
		
		// if node to be updated is in right subtree 
		else
			update(arr, 2 * si + 2, mid + 1, 
				se, idx, value); 

		// parent node's sum is the summation of left 
		// and right child 
		tree[si].sum = tree[2 * si + 1].sum + 
						tree[2 * si + 2].sum; 

		// parent node's prefix sum will be equivalent 
		// to maximum of left child's prefix sum or left 
		// child sum + right child prefix sum. 
		tree[si].prefixsum = 
					max(tree[2 * si + 1].prefixsum, 
					tree[2 * si + 1].sum + 
					tree[2 * si + 2].prefixsum); 

		// parent node's suffix sum will be equal to right 
		// child suffix sum or right child sum + suffix 
		// sum of left child 
		tree[si].suffixsum = 
					max(tree[2 * si + 2].suffixsum, 
					tree[2 * si + 2].sum + 
					tree[2 * si + 1].suffixsum); 

		// maxum will be the maximum of prefix, suffix of 
		// parent or maximum of left child or right child 
		// and summation of left child's suffix and 
		// right child's prefix. 
		tree[si].maxsum = 
					max(tree[si].prefixsum, 
					max(tree[si].suffixsum, 
					max(tree[2 * si + 1].maxsum, 
					max(tree[2 * si + 2].maxsum, 
					tree[2 * si + 1].suffixsum + 
					tree[2 * si + 2].prefixsum)))); 
	} 
} 

// fucntion to return answer to every type-1 query 
node query(int arr[], int si, int ss, 
		int se, int qs, int qe) 
{ 
	// initially all the values are INT_MIN 
	node result; 
	result.sum = result.prefixsum = 
				result.suffixsum = 
				result.maxsum = INT_MIN; 

	// range does not lies in this subtree 
	if (qe < ss || se < qs) 
		return result; 

	// complete overlap of range 
	if (qs <= ss && se <= qe) 
		return tree[si]; 

	int mid = (ss + se) / 2; 

	// right subtree 
	if (qs > mid) 
		return query(arr, 2 * si + 2, 
					mid + 1, se, qs, qe); 
		
	// left subtree	 
	if (qe <= mid) 
		return query(arr, 2 * si + 1, 
					ss, mid, qs, qe); 

	node left = query(arr, 2 * si + 1, 
					ss, mid, qs, qe); 
	node right = query(arr, 2 * si + 2, 
						mid + 1, se, qs, qe); 

	// finding the maximum and returning it 
	result.sum = left.sum + right.sum; 
	result.prefixsum = max(left.prefixsum, left.sum + 
						right.prefixsum); 
							
	result.suffixsum = max(right.suffixsum, 
					right.sum + left.suffixsum); 
	result.maxsum = max(result.prefixsum, 
					max(result.suffixsum, 
					max(left.maxsum, 
					max(right.maxsum, 
					left.suffixsum + right.prefixsum)))); 
					
	return result; 
} 

int main() 
{   int n; cin >> n;
    for(int i=0 ; i<n ; i++) cin >> a[i];

//	build(a, 0, n - 1, 0);

  // cout << query(a,0,0,n-1,1,2).maxsum << endl;
	return 0; 
} 
