#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

class Grafo {
public:
  int n;                    
  vector<vector <int>> adj; 
  vector<vector <int>> cap;
  vector<vector <int>> dur;

  Grafo(int n) {
    this->n = n;
    adj.resize(n+1);
    cap.resize(n+1);
    dur.resize(n+1);
    for (int i=1; i<=n; i++){
      cap[i].resize(n+1);
      dur[i].resize(n+1);
    }

  }
  
  void add_aresta(int a, int b, int c, int d) {
    // adjacencias do grafo nao dirigido, porque podemos ter de andar no sentido
    // contrario ao proatualarmos caminhos de aumento
    cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
    adj[a].push_back(b);
    adj[b].push_back(a);
    cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
    cap[a][b] = c;
    dur[a][b] = d;
  }

  // BFS para encontrar caminho de aumento
  // devolve valor do fluxo nesse caminho
  int bfs(int s, int t, vector<int> &pai) {
    for (int i=1; i<=n; i++) pai[i] = -1;

    pai[s] = -2;         
    queue<pair<int, int>> q; // fila do BFS com pares (no, capacidade)
    q.push({s, INT_MAX});    // inicializar com no origem e capacidade infinita

    while (!q.empty()) {
      // returar primeiro no da fila
      int atual = q.front().first;
      int fluxo = q.front().second;
      q.pop();

      // percorrer nos adjacentes ao no atual (atual)
      for (int prox : adj[atual]) {
	// se o vizinho ainda nao foi visitado (pai==-1)
	// e a aresta respetiva ainda tem capacidade para passar fluxo
	if (pai[prox] == -1 && cap[atual][prox]>0) {
	  pai[prox] = atual;                        // atualizar pai
	  int fluxo_novo = min(fluxo, cap[atual][prox]);  // atualizar fluxo
	  if (prox == t) return fluxo_novo;            // chegamos ao final?
	  q.push({prox, fluxo_novo});                  // adicionar a fila
	}
      }
    }
    
    return 0;
  }
  
  // Algoritmo de Edmonds-Karp para fluxo maximo entre s e t
  // devolve valor do fluxo maximo (cap[][] fica com grafo residual)
  int fluxo_max(int s, int t) {
    int fluxo = 0;             // fluxo a calcular
    vector<int> pai(n+1);  // vetor de pais (permite reconstruir caminho)
    
    while (true) {
      int fluxo_novo = bfs(s, t, pai); // fluxo de um caminho de aumento
      if (fluxo_novo == 0) break;         // se nao existir, terminar

      // imprimir fluxo e caminho de aumento
      cout << "Caminho de aumento: fluxo " << fluxo_novo << " | " << t;
      
      fluxo += fluxo_novo;  // aumentar fluxo total com fluxo deste caminho
      int atual = t;
      while (atual != s) { // percorrer caminho de aumento e alterar arestas
	int prev = pai[atual];	
	cap[prev][atual] -= fluxo_novo;
	cap[atual][prev] += fluxo_novo;
	atual = prev;
	cout << " <- " << atual; // imprimir proximo no do caminho
      }
      cout << endl;
    }
    
    return fluxo;
  }
Grafo load(string teste){
    int origem, destino, capacidade, duracao, vertices, ramos, numero, contador=0;

    ifstream file(teste);
    string line;
    getline(file, line);
    istringstream iss(line);
    //get first elements in file -> nodes and paths
    iss >> vertices >> ramos;
    Grafo grafo(vertices);

    while(file >> numero){
        switch (contador) {
            case 0:
                origem = numero;
                break;
            case 1:
                destino = numero;
                break;
            case 2:
                capacidade = numero;
                break;
            case 3:
                duracao = numero;
                grafo.add_aresta(origem, destino, capacidade, duracao);
                contador=-1;
                break;
            default:
                break;
        }
        contador++;
    }
    return grafo;
}
};



int main() {
  string teste;
  cin >> teste;
  Grafo g = load(teste);
  // Execucao exemplo usando 1 como no origem a 4 como o destino
  int fluxo = g.fluxo_max(1, 6);
  cout << "Fluxo maximo: " << fluxo << endl;

  return 0;
}

