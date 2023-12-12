#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <set>
#include <map>

namespace Arcade {
class Player {
  unsigned username;
  std::vector<unsigned> scores;

public:
  Player(unsigned, const std::vector<unsigned> &);
  explicit Player(unsigned);

  const std::vector<unsigned> &getScores() const;
  unsigned getUsername() const;

  void setScores(const std::vector<unsigned> &);
  void setUsername(unsigned);

  void print() const;




};

    inline bool operator < (const Player & lhs, const Player & rhs) {
        return lhs.getUsername() < rhs.getUsername();
    }

}

#endif /* PLAYER_H_ */
