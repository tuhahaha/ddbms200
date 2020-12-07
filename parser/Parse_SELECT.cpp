#include "Parse_SELECT.h"
using namespace std;


int main() {
    string sql_statement = "SELECT Customer.name,Book.title,Publisher.name,Orders.quantity FROM Customer,Book,Publisher,Orders WHERE Customer.id=Orders.customer_id and Book.id=Orders.book_id and Book.publisher_id=Publisher.id and Customer.id>308000 and Book.copies>100 and Orders.quantity>1 and Publisher.nation='PRC'";
    TREE Tree = SELECT(sql_statement,0);
    // TraverseTree(tree);
    return 0;
}
TCC GetTCC(string table_name, vector<string> column_list, vector<string> select_list) {
    // Get TCC for a table
   TCC tcc;
    for (int i = 0; i < column_list.size(); i++) {
        string table_tmp = GetBefore(column_list[i], ".");
        if (table_tmp == table_name && JudgeNotin(tcc.column_list,column_list[i])) { 
            tcc.column_list.push_back(column_list[i]);
        }
    }
    for (int i = 0; i < select_list.size(); i++) {
        string table_tmp = GetTableFromSelectCondition(select_list[i]);
        if (table_tmp == table_name) {
            tcc.condition_list.push_back(select_list[i]);
        }
    }
    // tcc.fratype = getTableFragType(table_name); // NEED TUTU
    tcc.table_name = table_name;
    return tcc;
}
vector<TCC> GetTCCList(vector<string> table_list, vector<string> column_list, vector<string> select_list) {
    vector<TCC> tcc_list;
    for (int i = 0; i < table_list.size(); i++) {
        TCC tcc = GetTCC(table_list[i], column_list, select_list);
        tcc_list.push_back(tcc);
    }
    return tcc_list; 
}
vector<string> GetSelectConditionList(vector<string> condition_list, vector<string> table_list) {
    vector<string> selectcondition_list;
    vector<string> tmp;
    vector<string> joincondition_list;
    // vector<string> condition_list = GetAllColumnList(sql_statement);
    for (int i = 0; i < condition_list.size(); i++) {
        tmp = GetColumnFromCondition(condition_list[i], table_list);
        if (tmp.size() == 2) {
            joincondition_list.push_back(condition_list[i]);
        }
        else if (tmp.size() == 1) {
            selectcondition_list.push_back(condition_list[i]);
        }
        else {
            cout << "ERROR: " << condition_list[i] << endl;
        }
    }
    return selectcondition_list;
}
vector<string> GetJoinConditionList(vector<string> condition_list, vector<string> table_list) {
    vector<string> selectcondition_list;
    vector<string> tmp;
    vector<string> joincondition_list;
    // vector<string> condition_list = GetAllColumnList(sql_statement);
    for (int i = 0; i < condition_list.size(); i++) {
        tmp = GetColumnFromCondition(condition_list[i], table_list);
        if (tmp.size() == 2) {
            joincondition_list.push_back(condition_list[i]);
        }
        else if (tmp.size() == 1) {
            selectcondition_list.push_back(condition_list[i]);
        }
        else {
            cout << "ERROR: " << condition_list[i] << endl;
        }
    }
    return joincondition_list;
}
bool JudgeNotin(vector<string> BigList, string item) {
    for (int i = 0; i < BigList.size(); i++) {
        if (item == BigList[i]){
            return false;
        }
    }
    return true;
}
bool JudgeNotinInt(vector<int> BigList, int item) {
    for (int i = 0; i < BigList.size(); i++) {
        if(item == BigList[i]) {
            return false;
        }
    }
    return true;
}
void TraverseTCCList(vector<TCC> TCCList) {
    for (int i = 0; i < TCCList.size(); i++) {
        cout << TCCList[i].table_name << endl;
        Traverse(TCCList[i].column_list);
        Traverse(TCCList[i].condition_list);
        cout << TCCList[i].fratype << endl;
    }
}
string GetTableFromSelectCondition(string select_condition) {
    string column;
    string table;
    if (select_condition.find("=") != -1) {
        column = GetBefore(select_condition,"=");
        table = GetBefore(column,".");
    }
    else if (select_condition.find(">") != -1) {
        column = GetBefore(select_condition,">");
        table = GetBefore(column,".");
    }
    else if (select_condition.find("<") != -1) {
        column = GetBefore(select_condition,"<");
        table = GetBefore(column,".");
    }
    else if (select_condition.find(">=") != -1) {
        column = GetBefore(select_condition,">=");
        table = GetBefore(column,".");
    }
    else if (select_condition.find("<=") != -1) {
        column = GetBefore(select_condition,"<=");
        table = GetBefore(column,".");
    }
    return table;
}
vector<string> GetTableFromJoinCondition(string join_condition) {
    vector<string> table_list;
    if (join_condition.find("=") != -1) {
        string column_1 = GetBefore(join_condition,"=");
        string column_2 = GetExactAfter(join_condition,"=");
        table_list.push_back(GetBefore(column_1,"."));
        table_list.push_back(GetBefore(column_2,"."));
    }
    return table_list;
}
vector<int> GetNodeListFromTableList(vector<string> table_in_join_condition, vector<TABLE> TableList) {
    vector<int> node_list;
    for(int i = 0; i < table_in_join_condition.size(); i++) {
        for (int j = 0; j < TableList.size(); j++) {
            if (table_in_join_condition[i] == TableList[j].table_name) {
                node_list.push_back(TableList[j].node_id);
            }
        }
    }
    return node_list;
}
vector<TCC> GetTCCListTest(string sql_statement) {
    vector<string> table_list = GetTableList(sql_statement);
    vector<string> column_list = GetAllColumnList(sql_statement);
    vector<string> condition_list = GetConditionList(sql_statement);
    vector<string> select_list = GetSelectConditionList(condition_list,table_list);
    vector<TCC> tccList = GetTCCList(table_list, column_list, select_list);
    for (int i = 0; i < tccList.size(); i++) {
        if (tccList[i].table_name == "Customer") {
            tccList[i].fratype = "V";
        }
        else if (tccList[i].table_name == "Publisher") {
            tccList[i].fratype = "H";
        }
        else if (tccList[i].table_name == "Orders") {
            tccList[i].fratype = "H";
        }
        else if (tccList[i].table_name == "Book") {
            tccList[i].fratype = "H";
        }
        else {
            cout << "ERROR IN ADDING FRAGTYP OF TCCLIST" << endl;
        }
    }
    return tccList;
}
vector<NODE> GetData(string sql_statement, int treeid) {
    vector<TCC> TCCList = GetTCCListTest(sql_statement);
    NODE node;
    vector<NODE> tree;
    int iid = 1;
    map<string,int> TableMap;
    // GetData
    for (int i = 0; i < TCCList.size(); i++) {
        string table_name = TCCList[i].table_name;
        if (TCCList[i].fratype == "H") {
            vector<string> condition_list = TCCList[i].condition_list;
            string condition = Link(condition_list, " AND ");
            for(int j = 1; j <= 4; j++) { 
                node.id = iid;
                node.site = j;
                node.child.clear();
                node.sql_statement = "SELECT * FROM " + table_name + "_" + to_string(j) + " WHERE " +  condition;
                iid += 1;
                tree.push_back(node);
            }
            node.id = iid;
            node.site = 1;
            node.child.clear();
            node.child.push_back(iid-4);
            node.child.push_back(iid-3);
            node.child.push_back(iid-2);
            node.child.push_back(iid-1);
            node.sql_statement = "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-4) + " UNION ALL " + "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-3) + " UNION ALL " + "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-2) + " UNION ALL " + "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-1);
            TableMap[table_name] = iid;          
            iid += 1;
            tree.push_back(node);
        }
        else if (TCCList[i].fratype == "V") {
            string key = GetKeyofTable(table_name)[0];
            for (int j = 1; j <= 4; j++) { 
                node.id = iid;
                node.site = j;
                node.child.clear();
                node.sql_statement = "SELECT * FROM " + table_name + "_" + to_string(j);
                iid += 1;
                tree.push_back(node);
            }
            string join_condition = Get_join_condition(treeid, iid-4, iid-3, key);
            node.id = iid;
            node.site = 1;
            node.sql_statement = join_condition;
            node.child.clear();
            node.child.push_back(iid-4);
            node.child.push_back(iid-3);
            iid += 1;
            tree.push_back(node);
            
            join_condition = Get_join_condition(treeid, iid-3, iid-2, key);
            node.id = iid;
            node.site = 3;
            node.sql_statement = join_condition;
            node.child.clear();
            node.child.push_back(iid-3);
            node.child.push_back(iid-2);
            iid += 1;
            tree.push_back(node);

            join_condition = Get_join_condition(treeid, iid-2, iid-1, key);
            node.id = iid;
            node.site = 1;
            node.sql_statement = join_condition;
            node.child.clear();
            node.child.push_back(iid-2);
            node.child.push_back(iid-1);
            TableMap[table_name] = iid; 
            iid+=1;
            tree.push_back(node);
        }
        else {
            cout << "INVALID FRAGTYPE :" << TCCList[i].fratype << endl; 
        }
    }

    // Join
    vector<string> condition_list = GetConditionList(sql_statement);
    vector<string> table_list = GetTableList(sql_statement);
    vector<string> join_condition_list = GetJoinConditionList(condition_list,table_list);
    // Traverse(join_condition_list);
    // TraverseTableList(TableList);
    // TraverseTableMap(TableMap);
    for (int i = 0; i < join_condition_list.size(); i++) {
        string column_1 = GetBefore(join_condition_list[i],"=");
        string column_2 = GetExactAfter(join_condition_list[i],"=");
        string table_1 = GetBefore(column_1,".");
        string table_2 = GetBefore(column_2,".");
        string pure_column_1 = GetExactAfter(column_1,".");
        string pure_column_2 = GetExactAfter(column_2,".");
        // cout << column_1 << " " << column_2 << endl;
        // cout << table_1 << " " << table_2 << endl;
        // cout << pure_column_1 << " " << pure_column_2 << endl;
        node.id = iid;
        node.child.clear();
        node.child.push_back(TableMap[table_1]);
        node.child.push_back(TableMap[table_2]);
        node.sql_statement = "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(TableMap[table_1]) + ",tree_" + to_string(treeid) + "_node_" + to_string(TableMap[table_2]) + " WHERE " + to_string(treeid) + "_node_" + to_string(TableMap[table_1]) + "." + pure_column_1 + "=" + "tree_" + to_string(treeid) + "_node_" + to_string(TableMap[table_2]) + "." + pure_column_2;
        TableMap[table_1] = iid;
        TableMap[table_2] = iid;
        tree.push_back(node);
        iid += 1;
    }
    node.id = iid;
    node.child.clear();
    node.child.push_back(iid-1);
    node.parent = 0;
    vector<string> select_column = GetSelectColumnList(sql_statement);
    string select = Link(select_column, ",");
    node.sql_statement = "SELECT " + select + "FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-1);
    iid += 1;

    // GetParent for result of GetData
    for (int i = 0; i < tree.size(); i++) {
        int node_id = tree[i].id;
        for(int j = i+1; j < tree.size(); j++) {
            if (JudgeNotinInt(tree[j].child, node_id) == 0) {
                tree[i].parent = tree[j].id;
                break;
            }
        }
    }
    tree[tree.size()-1].parent = 0;
    return tree;
}
TREE SELECT(string sql_statement, int treeid) {
    vector<TCC> TCCList = GetTCCListTest(sql_statement);
    TREE Tree;
    NODE node;
    vector<NODE> tree;
    Tree.tree_id = treeid;
    int iid = 1;
    map<string,int> TableMap;
    // GetData
    for (int i = 0; i < TCCList.size(); i++) {
        string table_name = TCCList[i].table_name;
        if (TCCList[i].fratype == "H") {
            vector<string> condition_list = TCCList[i].condition_list;
            string condition = Link(condition_list, " AND ");
            for(int j = 1; j <= 4; j++) { 
                node.id = iid;
                node.site = j;
                node.child.clear();
                node.sql_statement = "SELECT * FROM " + table_name + "_" + to_string(j) + " WHERE " +  condition;
                iid += 1;
                tree.push_back(node);
            }
            node.id = iid;
            node.site = 1;
            node.child.clear();
            node.child.push_back(iid-4);
            node.child.push_back(iid-3);
            node.child.push_back(iid-2);
            node.child.push_back(iid-1);
            node.sql_statement = "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-4) + " UNION ALL " + "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-3) + " UNION ALL " + "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-2) + " UNION ALL " + "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-1);
            TableMap[table_name] = iid;          
            iid += 1;
            tree.push_back(node);
        }
        else if (TCCList[i].fratype == "V") {
            string key = GetKeyofTable(table_name)[0];
            for (int j = 1; j <= 4; j++) { 
                node.id = iid;
                node.site = j;
                node.child.clear();
                node.sql_statement = "SELECT * FROM " + table_name + "_" + to_string(j);
                iid += 1;
                tree.push_back(node);
            }
            string join_condition = Get_join_condition(treeid, iid-4, iid-3, key);
            node.id = iid;
            node.site = 1;
            node.sql_statement = join_condition;
            node.child.clear();
            node.child.push_back(iid-4);
            node.child.push_back(iid-3);
            iid += 1;
            tree.push_back(node);
            
            join_condition = Get_join_condition(treeid, iid-3, iid-2, key);
            node.id = iid;
            node.site = 3;
            node.sql_statement = join_condition;
            node.child.clear();
            node.child.push_back(iid-3);
            node.child.push_back(iid-2);
            iid += 1;
            tree.push_back(node);

            join_condition = Get_join_condition(treeid, iid-2, iid-1, key);
            node.id = iid;
            node.site = 1;
            node.sql_statement = join_condition;
            node.child.clear();
            node.child.push_back(iid-2);
            node.child.push_back(iid-1);
            TableMap[table_name] = iid; 
            iid+=1;
            tree.push_back(node);

        }
        else {
            cout << "INVALID FRAGTYPE :" << TCCList[i].fratype << endl; 
        }
    }

    // Join
    vector<string> condition_list = GetConditionList(sql_statement);
    vector<string> table_list = GetTableList(sql_statement);
    vector<string> join_condition_list = GetJoinConditionList(condition_list,table_list);
    // Traverse(join_condition_list);
    // TraverseTableList(TableList);
    // TraverseTableMap(TableMap);
    for (int i = 0; i < join_condition_list.size(); i++) {
        string column_1 = GetBefore(join_condition_list[i],"=");
        string column_2 = GetExactAfter(join_condition_list[i],"=");
        string table_1 = GetBefore(column_1,".");
        string table_2 = GetBefore(column_2,".");
        string pure_column_1 = GetExactAfter(column_1,".");
        string pure_column_2 = GetExactAfter(column_2,".");
        // cout << column_1 << " " << column_2 << endl;
        // cout << table_1 << " " << table_2 << endl;
        // cout << pure_column_1 << " " << pure_column_2 << endl;
        node.id = iid;
        node.child.clear();
        node.child.push_back(TableMap[table_1]);
        node.child.push_back(TableMap[table_2]);
        node.sql_statement = "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(TableMap[table_1]) + ",tree_" + to_string(treeid) + "_node_" + to_string(TableMap[table_2]) + " WHERE " + to_string(treeid) + "_node_" + to_string(TableMap[table_1]) + "." + pure_column_1 + "=" + "tree_" + to_string(treeid) + "_node_" + to_string(TableMap[table_2]) + "." + pure_column_2;
        TableMap[table_1] = iid;
        TableMap[table_2] = iid;
        tree.push_back(node);
        iid += 1;
    }
    node.id = iid;
    node.child.clear();
    node.child.push_back(iid-1);
    node.parent = 0;
    vector<string> select_column = GetSelectColumnList(sql_statement);
    string select = Link(select_column, ",");
    node.sql_statement = "SELECT " + select + "FROM tree_" + to_string(treeid) + "_node_" + to_string(iid-1);
    iid += 1;

    // GetParent for result of GetData
    for (int i = 0; i < tree.size(); i++) {
        int node_id = tree[i].id;
        for(int j = i+1; j < tree.size(); j++) {
            if (JudgeNotinInt(tree[j].child, node_id) == 0) {
                tree[i].parent = tree[j].id;
                break;
            }
        }
    }
    tree[tree.size()-1].parent = 0;
    Tree.root = iid-1;
    Tree.Nodes = tree;
    return Tree;
}
void TraverseTree(vector<NODE> tree) {
    for(int i = 0; i < tree.size(); i++) {
        cout << "== "<< tree[i].id << " ==" << endl;
        cout << "site =>" << tree[i].site << endl;
        cout << "sql_statement =>" << tree[i].sql_statement << endl;
        cout << "child =>" << endl;
        TraverseInt(tree[i].child);
        cout << "parent =>" << endl;
        cout << tree[i].parent << endl;
    }
}
void TraverseInt(vector<int> intlist) {
    for (int i = 0; i < intlist.size(); i++){
        cout << intlist[i] << endl;
    }
}
void TraverseTableMap(map<string,int> TableMap) {
    map<string, int>::iterator iter;
    iter = TableMap.begin();
    while(iter != TableMap.end()) {
        cout << iter->first << " : " << iter->second << endl;
        iter++;
    }
}
vector<string> GetKeyofTable(string table_name) {
    vector<string> keys;
    if (table_name == "Customer") {
        keys.push_back("id");
    }
    if (table_name == "Book") {
        keys.push_back("id");    
    }
    if (table_name == "Publisher") {
        keys.push_back("id");    
    }
    if (table_name == "Orders") {        
        keys.push_back("Customer_id");
        keys.push_back("Book_id");
    }
    return keys;
}
vector<string> GetFullKeyofTable(string table_name) {
    vector<string> keys = GetKeyofTable(table_name);
    vector<string> fullkeys;
    for (int i = 0; i < keys.size(); i++) {
        fullkeys.push_back(table_name + "." +keys[i]);
    }
    return fullkeys;
}
string Get_join_condition(int treeid, int a, int b, string key) {
    return "SELECT * FROM tree_" + to_string(treeid) + "_node_" + to_string(a) + ",tree_" + to_string(treeid) + "_node_" + to_string(b) + " WHERE " + "tree_" + to_string(treeid) + "_node_" + to_string(a) + "." + key + "=" + "tree_" + to_string(treeid) + "_node_" + to_string(b) + "." + key; 
}