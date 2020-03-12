
#include <iostream>

using namespace std;

#define Select_Num 10

 

void Select(char* arr, int start, int* result, int count, const int Num, const int arr_len)

{

	int i = 0;

	for(i = start;i<arr_len+1-count;i++)

	{

		result[count-1] = i;

		if(count-1 == 0)

		{

			int j;

			for(j = Num - 1;j >=0;j--)

			{

				cout<<arr[result[j]]<<' ';

			}

			cout<<endl;

		}

		else

		{

			Select(arr, i+1, result, count-1, Num, arr_len);

		}

	}

}

 
int main()

{

	//char arr[13] = {'a','b','c','d','e','f','g','h','i','k','j','l','m'};

	//int result[Select_Num];

	
			char a=3+16+'0';
			cout<<a;
		
		cout<<endl;
	//Select(arr,0,result,Select_Num,Select_Num,sizeof(arr)/sizeof(int));

}

