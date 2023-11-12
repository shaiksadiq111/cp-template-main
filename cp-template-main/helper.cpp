
int M = 1e9 + 7;

vector<ll> fac(N, 1);
void Fac(){
   fac[1]=1;
    f(i, 2, fac.size()){
        fac[i]=((ll)fac[i-1]*(ll)i)%M;
    }
}  


long long int Pow(int a, int b){
   if(b == 0){
    return 1;
   }
 
   long long res = Pow(a, b/2);
   res = res*res % M;
   if(b % 2){
    res = a*res % M;
   }
   return res;
}



int comb(long long n, long long r){
	if(r == 0){
		return 1;
	}

	long long answer = fac[n];
	answer = ((answer*Pow(fac[r], M-2)) % M);
	answer = ((answer*Pow(fac[n - r], M-2)) % M);
	return answer;

}


vector<string> giveWords(string &s){
	vector<string> answer;
	string temp = "";
	for(auto i : s){
		if(i == ' '){
			answer.push_back(temp);
			temp = "";
		}else{
			temp += i;
		}
	}

	if(temp.size()){
		answer.push_back(temp);
	}

	return answer;
}




int N;
vector<bool> prime;
void sieve(){
   prime = vector<bool>(N+1, true);
   prime[1] = false;
   for(int p = 2; p*p <= N; p++){
      if(prime[p] == true){
         for(int i = p*p; i <= N; i+= p){
            prime[i] = false;
         }
      }
   }
}


void createGraph(){
	int n;
	vector<vector<int>> graph(n);
	for(auto i : edges){
		graph[i[0]].push_back(i[1]);
		graph[i[1]].push_back(i[0]);
	}
}


  long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);   
}


    
  long long inv(long long a) {
  return a <= 1 ? a : M - (long long)(M/a) * inv(M % a) % M;
}

    


 


unordered_set<int> primeFactors(int n)
{
   unordered_set<int> s;
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n/i;
        }
    }
    if (n > 2)
         s.insert(n);

   return s;

}

bool checkVowel(char c){
       return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
       	c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        
   }



   vector<int> KMPprefixArray(string &s){
        vector<int> answer(s.size(), 0);

        int p = 0;
        for(int i = 1; i <  s.size(); i++){
            int j = answer[i-1];

            while(j > 0 && s[i] != s[j]){
                j = answer[j-1];
            }


            if(s[i] == s[j]){
                j++;
            }

            answer[i] = j;
        }


        return answer;
      
    }