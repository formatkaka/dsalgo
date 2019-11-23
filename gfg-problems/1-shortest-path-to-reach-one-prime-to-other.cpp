//
// Created by Siddhant on 2019-11-22.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"
#include "cmath"
#include "list"
#include "unordered_set"
#include "unordered_map"

using namespace std;

class Graph {
    int V;
    list<int> *l;

public:

    Graph(int v) {

        this->V = v;
        this->l = new list<int>[v];

    }

    void addEdge(int v1, int v2) {

        l[v1].push_back(v2);
        l[v2].push_back(v1);

    }

    int shortestDistance(int n1, int n2) {

        queue<int> q;
        q.push(n1);
        unordered_set<int> visited;

        visited.insert(n1);
        int val = 0;
        while (!q.empty()) {

            int q_size = q.size();

            while (q_size > 0) {
                int nodeval = q.front();
                q.pop();

                for (auto it = l[nodeval].begin(); it != l[nodeval].end(); ++it) {

                    if (visited.find(*it) == visited.end()) {

                        visited.insert(*it);
                        q.push(*it);
                    }
//                    cout << *it << endl;
                    if (*it == n2) {
                        return val;
                    }

                }
                q_size--;
            }

            val++;

        }

        return -1;

    }

};

void SieveOfEratosthenes(vector<int> &v) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    int n = 9999;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {

        // If prime[p] is not changed, then it is a prime
        if (prime[p]) {

            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Forming a vector of prime numbers
    for (int p = 1000; p <= n; p++)
        if (prime[p])
            v.push_back(p);
}

bool compare(int num1, int num2) {
    // To compare the digits
    string s1 = to_string(num1);
    string s2 = to_string(num2);
    int c = 0;
    if (s1[0] != s2[0])
        c++;
    if (s1[1] != s2[1])
        c++;
    if (s1[2] != s2[2])
        c++;
    if (s1[3] != s2[3])
        c++;

    // If the numbers differ only by a single
    // digit return true else false
    return (c == 1);
}

int findAllPrimes(int n1, int n2) {

    vector<int> primes;
    SieveOfEratosthenes(primes);

    Graph g(primes.size());

    for (int i = 0; i < primes.size(); ++i) {

        for (int j = i + 1; j < primes.size(); ++j) {

            if (compare(primes[i], primes[j])) {

                g.addEdge(i, j);

            }

        }

    }

    int in1, in2;
    for (int j = 0; j < primes.size(); j++) {
        if (primes[j] == n1) {
            in1 = j;
        }
        if (primes[j] == n2) {
            in2 = j;
        }
    }


    return g.shortestDistance(in1, in2);

}


int main() {

    cout << findAllPrimes(1373, 8017);
    return 0;
}