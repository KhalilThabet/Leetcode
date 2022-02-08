/*
 Definition for a Node.
class Node {
	public:
		    int val;
		        vector<Node*> neighbors;
			    Node() {
				            val = 0;
					            neighbors = vector<Node*>();
						        }
			        Node(int _val) {
					        val = _val;
						        neighbors = vector<Node*>();
							    }
				    Node(int _val, vector<Node*> _neighbors) {
					            val = _val;
						            neighbors = _neighbors;
							        }
};
*/

class Solution {
	public:
		    Node* cloneGraph(Node* node) {
			            if (node==nullptr) return node;
				            map<Node*,Node*> HashMap;
					            Node* CurrentNodeClone;
						            int a=0;
							            while(1){
									                a++;
											            if (HashMap.find(node)==HashMap.end())
													                    
													                    CurrentNodeClone=new Node(node->val);
												                
												                else{
															                
															                CurrentNodeClone=HashMap[node];
																	                
																	            }
														                
														            HashMap[node]=CurrentNodeClone;
															                vector<Node*> Temp;
																	            Temp.push_back(CurrentNodeClone);
																		                for (int i=0;i<node->neighbors.size();i++){

																					                if (HashMap.find(node->neighbors[i])!=HashMap.end()){
																								                    HashMap[node->neighbors[i]]->neighbors.push_back(CurrentNodeClone);

																										                    }
																							                else{
																										                    cout<<"NOT HERE\n";
																												                        Node* NewNodeClone=new Node(node->neighbors[i]->val,Temp);
																															                    HashMap[node->neighbors[i]]=NewNodeClone;
																																	                    }
																									            }
																				                        cout<<(a==2?"OKAY\n":"");

																							            map<Node*,Node*>::iterator itr=HashMap.find(node);
																								                itr++;
																										            node=itr->first;
																											                if (itr==HashMap.end()) break;
																													        }
								            Node* NodeClone;
									            for(auto e:HashMap){
											                NodeClone=e.second;break;
													        }
										            return NodeClone;
											        }
};
