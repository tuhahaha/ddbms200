#include<iostream>    //std::cout std::endl
#include <vector>
#include<thread>      //std::thread
#include<future>      //std::future std::promise
#include<utility>     //std::ref
#include<chrono>      //std::chrono::seconds
// #include<string>

void test2(int num){
   std::cout << &num << std::endl;
}

void initiazer(std::promise<int> &promiseObj, int output[5], int i){
   int j = 3;
   j++;

   // std::cout << &output[i] << std::endl; //啊内部所有空间也要另外申请我人没了
   // std::cout << "Inside thread: " << std::this_thread::get_id() << std::endl;
   std::this_thread::sleep_for(std::chrono::seconds(1));
   j++;
   // std::cout << "Inside thread: " << std::this_thread::get_id() << &j << j << std::endl;
   // std::cout << j << std::endl;
   // printf("%d\n", &j);
   std::this_thread::sleep_for(std::chrono::seconds(1));
   j++;
   std::cout << j << std::endl; //啊内部所有空间也要另外申请我人没了
   promiseObj.set_value(35);
}

int main(){
   // vector<std::future<int>> futures;
   // std::vector<std::future<int>*> futures; //先把指针的空间给申请好，指针是可以copy的（vector pushback的方式是copy）
   // std::vector<std::thread*> ths; // 不得行，指针并不会附带申请后面的空间
   // std::vector<std::promise<int>*> prom;
   std::future<int> futures[5]; //先把空间给申请好
   std::thread ths[5];
   std::promise<int> prom[5];
   int output[5];
   for(int i = 0; i < 5; i++){
      // int j = 3;
      // std::cout << &j << std::endl;
      // std::promise<int> promiseObj; // 同一个promiseObj上反复调用get_future会抛出future_error异常。
      futures[i] = prom[i].get_future(); //直接放进去
      // std::future<int> futureObj = promiseObj.get_future();
      // futures[i] = &futureObj;
      ths[i] = std::thread(initiazer, std::ref(prom[i]), output, i);
    
      // std::cout << futureObj.get() << std::endl;
      
      printf("waiting for %d\n", i);
   }
   for(int i = 0; i < 5; i++){
      // std::future<int> futureObj = (*f).get_future();
      // std::cout << "OK" << std::endl;
      // std::cout << f << std::endl;
      std::cout << futures[i].get() << std::endl; //futures[i]是个指针，直接调用
   } // 如果放在前面，似乎调用get会直接error，如果放在后面，前面的因为join顺次跑完，到了这里什么也拿不出来

   for(int i = 0; i < 5; i++){
      ths[i].join(); //目测join的功能是完备的
   }

   printf("all done!\n");
    
    return 0;
}