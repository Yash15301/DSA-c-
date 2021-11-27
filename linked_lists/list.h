
//Forward declaration
class List;

class Node{
    int data;
    
public:
    Node* next;
    Node(int d):data(d),next(NULL){}

    int getData(){
        return data;
    }

    friend class List;
};

class List{
    Node * head;
    Node * tail;

     int searchHelper(Node *start, int key){
        if(start==NULL){
            return -1;
        }
        if(start->data == key){
            return 0;
        }
        // recursive call on smaller list

        int subIdx = searchHelper(start->next,key);
        if(subIdx==-1){
            return -1;
        }
        return subIdx+1;
    }

public:
    List():head(NULL),tail(NULL){}

    Node* begin(){
        return head;
    }
    void push_front(int data){
        if(head==NULL){
            Node * n = new Node(data);
            head = tail = n;
            return;
        }
        else{
            Node* n = new Node (data);
            Node * next = new Node(data);
            n->next = head;
            head = n;
        }
    }

    void push_back(int data){
        if(head==NULL){
            Node * n = new Node(data);
            head = tail = n;

        }
        else{
            Node * n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    void insert(int data, int pos){
        if(pos==0){
            push_front(data);
            return;
        }
        Node* temp = head;
        for(int jump=1; jump<=pos-1; jump++){
            temp = temp->next;
        }
        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteHead(Node*&head){
        if(head==NULL){
            return;
        }
        else{
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    int search(int key){
        Node *temp = head;
        int idx=0;

        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    int recursiveSearch(int key){
        int idx = searchHelper(head,key);
    }

    void pop_front(){
        Node *temp = head;
        head = head->next;
        temp->next=NULL;
        delete temp;
    }
};