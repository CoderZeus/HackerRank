#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
//#include <threads.h>

using namespace std;


enum   actions { BUY,SELL,CANCEL,MODIFY,MODIFY_BUY,MODIFY_SELL,PRINT,UNKNOWN};


class Trade
{
    protected:
    bool m_isActive;
    actions m_action;
    uint64_t  m_quantity;
    uint64_t m_price;    
    string m_orderType;
    string m_orderId;
    
    
    public:
    Trade();
    Trade(string,string,string,int,int);
    ~Trade();
    
    string getOrderId(){return m_orderId;};
    string getOrderType(){return m_orderType;};
    uint64_t getPrice(){return m_price;};
    uint64_t getQuantity(){return m_quantity;};
    bool     getStatus(){return m_isActive;};
    void     setStatus(bool status){m_isActive = status;};
    void     setQuantity(uint64_t quantity){ m_quantity = quantity;};
    
    actions getAction(){return this->m_action;};
    bool readInput(string &input,Trade * &);
    protected:
    
    void setValues(string &,actions,string &,string &,string &);
    
    
    actions getAction(string action)
    {
        actions operation = BUY;
        if(action.compare("BUY") == 0)
        {
            operation = BUY;
        }
        else if(action.compare("SELL") ==0)
        {
            operation = SELL;
        }
        else if(action.compare("MODIFY") ==0)
        {
            operation = MODIFY;
        }
        else if(action.compare("CANCEL") ==0)
        {
            operation = CANCEL;
        }
         else if(action.compare("PRINT") ==0)
        {
            operation = PRINT;
        }
        else
        operation = UNKNOWN;
        
    
      return operation;  
    }
   
   bool isValidTrade()
   {
       if(this->m_action == UNKNOWN)
          return false;
       if(this->m_quantity <= 0)
          return false;
          
       if( this->m_price <= 0)
          return false;
       
       if( ( this->m_orderType.compare("GFD") ==0 || this->m_orderType.compare("IOC") ==0 ) == 0)//if neither err
          return false;
          
      return true;    
   } 
    
};

Trade::Trade()
{
    this->m_isActive = true;
}

Trade::~Trade()
{
    this->m_isActive = false;
}

Trade::Trade(string orderId,string action,string orderType,int quantity,int price)
{
    this->m_action = getAction(action);
    this->m_isActive = true;
    
    this->m_quantity = quantity;
    this->m_price = price;    
    this->m_orderType =orderType;
    this->m_orderId = orderId;
}

void Trade::setValues(string &orderId,actions action,string& orderType,string& quantity,string& price)
{
    this->m_action = action;//getAction(action);
    this->m_isActive = true;
    
    try
     {
      this->m_quantity = std::stoi(quantity);
      this->m_price = std::stoi(price);    
    } 
    catch (exception &ex) 
    {
       this->m_quantity = 0;
       this->m_price = 0;    
    }
    
    this->m_orderType =orderType;
    this->m_orderId = orderId;
}



bool Trade ::readInput(string &input,Trade * &pTrade)
{
       
    vector<string> data = std::vector<string> ();
    int start_pos =0;
   // cout<<"Input "<<input<<"Size "<<input.size();
    string temp_x;
    for (int i =0; i <input.size() ;++i )
    {
        
        if(input.at(i)==' ')
        {

           // cout<<" \n Substr "<<start_pos<<": "<<i<<endl;
        temp_x= (input.substr(start_pos,i-start_pos));
        //cout<<" Item : "<<temp_x;
        data.push_back(temp_x);
            start_pos = i+1;

        //cout<<"\nSpace found at pos "<<i<<endl;
        
        }
    //else
    // cout<<" \n "<<input.at(i)<<" " <<i<<endl;
    }
    data.push_back(input.substr(start_pos,input.size()-start_pos));

   // return true;
   //
       // cout<<"Going to use data ";

//    return true;
        actions operation = getAction(data.at(0));
        pTrade = new Trade();
        //pTrade = NULL;
        //return true;
    //cout<<"Data size"<<data.size()        ;
    //for (int x=0 ; x < data.size(); ++x)
    //    cout<<" item :"<<x<<" "<<data.at(x)<<endl;
        switch (operation)
        {
            
            case BUY  :             
            case SELL :  
                       {
                         // pTrade = new Trade();
                          pTrade->setValues(data.at(4),operation,data.at(1),data.at(3),data.at(2));
                          break;
                       }  
            
            case MODIFY :   
                         {
                            //pTrade = new Trade();
                            actions value = getAction(data.at(2));
                            if(value == BUY)
                               value = MODIFY_BUY;
                            else 
                                value = MODIFY_SELL;  
                string type ="GFD"; 
                            pTrade->setValues(data.at(1),value,type,data.at(3),data.at(4));
                            break;
                         }
                         
            case CANCEL:
                         //pTrade = new Trade();
                         pTrade->m_action = operation;
                         pTrade->m_orderId = data.at(1);
                         break;
            case PRINT:  
                        //pTrade = new Trade();
                         pTrade->m_action = operation;
                         break;
                                                  
            case UNKNOWN :
                         {
                           delete pTrade;
                            pTrade = NULL;
                            break;
                            return false;  
                         } 
                            
            default:
                     return true;                
        }
    
        
  return true;      
}
    
class BookManager //: public Thread
{
    protected:
    queue<Trade *> m_activeTrade;
    map<string,Trade * > m_indexBook;
    map<uint64_t, vector<Trade *> > m_buyBook;
    map<uint64_t, vector<Trade *> > m_sellBook;
 
    public:    
    BookManager();
    ~BookManager();
    
    bool addTrade(Trade *);
    bool executeTrade();
    
    private:
    void matchOrders(vector<Trade *> &list,Trade* pTrade);
    void printOrders();
    bool addBuyOrder(Trade * pTrade);
    bool insertToBuyBook(Trade *pTrade,bool isNewEntry = true);
    bool removeBuyOrder();
    bool addSellOrder(Trade * pTrade);
    bool insertToSellBook(Trade *pTrade,bool isNewEntry = true);
    bool removeSellOrder();
    bool modifyOrder(Trade* pTrade);
    bool cancelOrder(Trade * pTrade);
};

BookManager::BookManager()
{
    
}
    BookManager::~BookManager()
    {
        
    }

 bool BookManager::addTrade(Trade * pTrade)
 {
     if(pTrade)
     {
          this->m_activeTrade.push(pTrade);
          
     }
     else 
     {
         cout<<"NULL pointer";
         return false;
     }
    return true; 
 }
 
  bool BookManager::insertToBuyBook(Trade *pTrade,bool isNewEntry)
  {
      if(pTrade->getStatus()&& pTrade->getOrderType().compare("GFD") == 0)
        {
            if( (isNewEntry) && (this->m_indexBook.find(pTrade->getOrderId()) != this->m_indexBook.end() ) ) 
            {
               // cout<<"Duplicate entry ";
               // return false;
            }
            
            map<uint64_t, vector<Trade *>>::iterator it = this->m_buyBook.find(pTrade->getPrice());
            if(it != this->m_buyBook.end())
            {
                it->second.push_back(pTrade);
            }
            else 
            {              
             // this->m_buyBook[pTrade->getPrice()].insert(std::pair<string,Trade*> (pTrade->getOrderId(), pTrade)); 
             vector<Trade*> listVec ;//=  std::vector<Trade*> ();
             listVec.push_back(pTrade);
               this->m_buyBook[pTrade->getPrice()]=listVec;  
            }
            
            this->m_indexBook[pTrade->getOrderId()]= pTrade;           
             
        }
        
        return true;
  }

bool BookManager::addBuyOrder(Trade *pTrade)
{
    if(this->m_sellBook.size())
    {
        map<uint64_t, vector<Trade *> >::reverse_iterator sIterator = this->m_sellBook.rbegin();
        
        while(pTrade->getStatus() && sIterator!= this->m_sellBook.rend() )
        {
           if(sIterator->first > pTrade->getPrice())
        {
            this->insertToBuyBook(pTrade);
        }
        else
        {
           vector<Trade *> list = sIterator->second;           
           this->matchOrders(list,pTrade);
           
           if( list.size() == 0 )
              this->m_sellBook.erase(sIterator->first);
              
           if(pTrade->getStatus() == true) 
               this->insertToBuyBook(pTrade);   
            
        } 
        ++sIterator;
        }
        
        
    }
    else
    {        
        this->insertToBuyBook(pTrade);     
    }
    return true;
}


bool BookManager::addSellOrder(Trade *pTrade)
{
    if(this->m_buyBook.size())
    {
        map<uint64_t, vector<Trade *> >::reverse_iterator sIterator = this->m_buyBook.rbegin();
        
         while(pTrade->getStatus() && sIterator!= this->m_buyBook.rend() )
        {
        
        if(sIterator->first < pTrade->getPrice())
        {
            this->insertToSellBook(pTrade);
        }
        else
        {
           vector<Trade *> list = sIterator->second;           
           this->matchOrders(list,pTrade);
           
           if( list.size() == 0 )
              this->m_sellBook.erase(sIterator->first);
              
           if(pTrade->getStatus() == true) 
               this->insertToSellBook(pTrade);   
            
        }
        ++sIterator;
        }
    }
    else
    {        
        this->insertToSellBook(pTrade);     
    }
    return true;
}


 bool BookManager::insertToSellBook(Trade *pTrade,bool isNewEntry )
  {
      if(pTrade->getStatus()&& pTrade->getOrderType().compare("GFD") == 0)
        {
            if( (isNewEntry) && (this->m_indexBook.find(pTrade->getOrderId()) != this->m_indexBook.end() ) ) 
            {
                //cout<<"Duplicate entry ";
                //return false;
            }
            
            map<uint64_t, vector<Trade *>>::iterator it = this->m_sellBook.find(pTrade->getPrice());
            if(it != this->m_sellBook.end())
            {
                it->second.push_back(pTrade);
            }
            else 
            {              
             // this->m_buyBook[pTrade->getPrice()].insert(std::pair<string,Trade*> (pTrade->getOrderId(), pTrade)); 
               //this->m_sellBook.insert(std::pair<uint64_t,vector<Trade *>(pTrade->getPrice(),{pTrade}));
               this->m_sellBook[pTrade->getPrice()] ={pTrade};
            }
            
            this->m_indexBook[pTrade->getOrderId()]= pTrade;           
             
        }
        
        return true;
  }

bool BookManager::cancelOrder(Trade * pTrade)
{
    Trade *temp = NULL;
    if(pTrade)
    {
        map<string,Trade * >::iterator it = this->m_indexBook.find(pTrade->getOrderId());
        map<uint64_t, vector<Trade *>>::iterator sIterator ;
        if(it != this->m_indexBook.end())
        {
            temp = it->second;
            if(temp->getAction() == BUY)
            {
               sIterator = this->m_buyBook.find(temp->getPrice());       
            }            
            else 
            {
                sIterator = this->m_sellBook.find(temp->getPrice());  
            }
            
            vector<Trade* > list = sIterator->second;
            vector<Trade* >new_list ;
            for (int x=0; x<list.size();++x)
            {
                if( list.at(x)->getOrderId() != pTrade->getOrderId() )
                   new_list.push_back(list.at(x));
                else
                 {
                     delete list.at(x);
                     list.at(x) = NULL; 
                 }   
            }
           this->m_indexBook.erase(pTrade->getOrderId()); 
           return true;
        }
         
    }
    return false;
}

void BookManager::matchOrders(vector<Trade *> &list,Trade* pTrade )
{
    
           Trade *temp = NULL;
           int last_pos = 0;
           for( int i=0;i< list.size() ; ++i)
           {
               temp = list.at(i);
               if(temp&&temp->getStatus())
               {
                    if(pTrade->getQuantity() > temp->getQuantity())
                    {
                        cout<<"TRADE "<<temp->getOrderId()<<" "<<temp->getPrice()<<" "<<temp->getQuantity()<<" ";
                        cout<<""<<pTrade->getOrderId()<<" "<<pTrade->getPrice()<<" "<<temp->getQuantity()<<" "<<endl;
                        
                        temp->setStatus(false);
                        
                        pTrade->setQuantity(pTrade->getQuantity() - temp->getQuantity());
                        temp->setQuantity(0);
                        
                        this->m_indexBook.erase(temp->getOrderId());
                        last_pos = i;
                    }
                    else if(pTrade->getQuantity() == temp->getQuantity())
                    {
                        cout<<"TRADE "<<temp->getOrderId()<<" "<<temp->getPrice()<<" "<<temp->getQuantity()<<" ";
                        cout<<""<<pTrade->getOrderId()<<" "<<pTrade->getPrice()<<" "<<pTrade->getQuantity()<<" "<<endl;
                        
                        temp->setStatus(false);
                        pTrade->setStatus(false);
                        pTrade->setQuantity(0);
                        
                        this->m_indexBook.erase(temp->getOrderId());
                        
                        last_pos = i;
                        break;   //operation over                     
                        
                    }  
                    
                    else 
                    {
                        cout<<"TRADE "<<temp->getOrderId()<<" "<<temp->getPrice()<<" "<<temp->getQuantity()<<" ";
                        cout<<""<<pTrade->getOrderId()<<" "<<pTrade->getPrice()<<" "<<pTrade->getQuantity()<<" "<<endl;                       
                        temp->setQuantity(temp->getQuantity() - pTrade->getQuantity());
                        pTrade->setStatus(false);
                        pTrade->setQuantity(0);   
                        
                        last_pos = i;
                        break;   //operation over          
                        
                    }
                                    
               }
           }
           
           
           {
               Trade * tTrade = NULL;
               vector<Trade *> new_list = std::vector<Trade *> ();
               for( int x= 0 ; x < list.size() ; ++x)
               {
                   tTrade = list.at(x);
                   if(tTrade && tTrade->getStatus())
                   {
                       new_list.push_back(tTrade);
                   }
                   else 
                   {
                      delete tTrade;
                      tTrade = NULL;
                   }
               }
               //list.clear();
               if(last_pos != list.size() -1 )
                    list = new_list; 
           }
          
}

bool BookManager::modifyOrder(Trade* pTrade)
{
     if(pTrade)
     {
         Trade * tTrade = NULL;
         map<string,Trade * >::iterator it = this->m_indexBook.find(pTrade->getOrderId());
         
         if(it != this->m_indexBook.end())
         {
             tTrade = it->second;
             this->cancelOrder(tTrade);
             
             if(pTrade->getAction() == MODIFY_BUY)
             {
                 this->addBuyOrder(pTrade);
             }
             else
              {
                 this->addSellOrder(pTrade);
             }
         }
     }
     return true;
}

void BookManager::printOrders()
{
    cout<<"SELL:"<<endl;
    map<uint64_t, vector<Trade *> >::reverse_iterator sIterator = this->m_sellBook.rbegin();
    while(sIterator != this->m_sellBook.rend() )
    {
        vector<Trade*> list = sIterator->second;
        int count =0;
        for(int i =0;i< list.size(); ++i )
        {
            if(list.at(i)->getStatus())
                count = count + list.at(i)->getQuantity();
        }
        if(count> 0)
            cout<<sIterator->first<<" "<<count<<endl;
        ++sIterator;
    } 
    
    
     cout<<"BUY:"<<endl;
    map<uint64_t, vector<Trade *> >::reverse_iterator sIterator2 = this->m_buyBook.rbegin();
    while(sIterator2 != this->m_buyBook.rend() )
    {
        vector<Trade*> list = sIterator2->second;
        int count =0;
        for(int i =0;i< list.size(); ++i )
        {
            if(list.at(i)->getStatus())
                count = count + list.at(i)->getQuantity();
        }
        if(count> 0)
            cout<<sIterator2->first<<" "<<count<<endl;
        ++sIterator2;
    } 
    
    
}

bool BookManager::executeTrade()
{
    if(this->m_activeTrade.size())
    {
        Trade *pTrade = this->m_activeTrade.front();
        this->m_activeTrade.pop();
        if(pTrade)
        {
            switch(pTrade->getAction())
            {
                case BUY :  this->addBuyOrder(pTrade);
                            break;
                                    
                case SELL: this->addSellOrder(pTrade);
                            break;
                case MODIFY_BUY:
                case MODIFY_SELL: 
                                  this->modifyOrder(pTrade);
                                  break;
                case CANCEL:
                                this->cancelOrder(pTrade);
                                break;
                case PRINT:     this->printOrders();
                                break;
                
                
                default :
                         cout<<"Default case";
                        break;
            }
        }
        
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   
    
    BookManager *manager = new BookManager();
    
    int count =0;
    string dataLine = std::string();
    Trade *pTrade = NULL;
    //cout<<"Starting ";
    while(getline(cin,dataLine))
    {
        //cin>>dataLine;
    
        //cout<<"Data "<<dataLine<<endl;
        if(pTrade->readInput(dataLine,pTrade) == true)
        {
            manager->addTrade(pTrade);
            manager->executeTrade();
        }
        else
        {
            cout<<"Failed ";
        }
        
    };
    
    
  return 0;  
}

