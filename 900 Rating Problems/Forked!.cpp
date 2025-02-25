#include <bits/stdc++.h>
using namespace std;

bool isAttackPoint(int xQueen, int yQueen, int xKnight, int yKnight, int a, int b) {
  int xdiff = abs(xQueen - xKnight);
  int ydiff = abs(yQueen - yKnight);

  return (xdiff == a and ydiff == b) or (xdiff == b and ydiff == a);
}

set<pair<int, int>> knightMoves(int xKnight, int yKnight, int a, int b) {
  set<pair<int, int>> moves;
  moves.insert({xKnight + a, yKnight + b});
  moves.insert({xKnight + a, yKnight - b});
  moves.insert({xKnight - a, yKnight + b});
  moves.insert({xKnight - a, yKnight - b});
  moves.insert({xKnight + b, yKnight + a});
  moves.insert({xKnight + b, yKnight - a});
  moves.insert({xKnight - b, yKnight + a});
  moves.insert({xKnight - b, yKnight - a});

  return moves;
}

int forkedPoints() {
  int a, b; cin >> a >> b;
  int xKing, yKing; cin >> xKing >> yKing;
  int xQueen, yQueen; cin >> xQueen >> yQueen;

  int points = 0;

  set<pair<int, int>> attackPoints = knightMoves(xKing, yKing, a, b);
  for (auto attackPoint : attackPoints) {
    if (isAttackPoint(xQueen, yQueen, attackPoint.first, attackPoint.second, a, b)) points++;
  }
  
  return points;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << forkedPoints() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1904/A