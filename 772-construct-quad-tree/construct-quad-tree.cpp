/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:

    Node* solve(int r, int c ,vector<vector<int>> & grid,int n){

        int val = grid[r][c];
        bool same = true;

        for(int i = r;i<r+n;i++){
            for(int j = c;j<c+n;j++ ){
                if(grid[i][j]!=val){
                    same = false;
                    break;

                }
            }
        }

        if(same){
            return new Node(val,1);
        }

        int half = n/2;

        Node* l1 = solve(r,c,grid,half);
        Node* r1 = solve(r, c+half,grid ,half);
        Node* l2 = solve(r+half,c,grid,half);
        Node* r2 = solve(r+half,c+half,grid,half);

        return new Node(val,0,l1,r1,l2,r2);
    }
    Node* construct(vector<vector<int>>& grid) {
        return solve(0,0,grid,grid.size());
        
    }
};