#include <iostream>
#include <algorithm>

#include "search.hh"
#include "timing.hh"

namespace Arcade {
bool binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username) {
  timing::time_point start = std::chrono::steady_clock::now();

  std::vector<Arcade::Player>::const_iterator begin = player_vec.begin(), end = player_vec.end(),
  // original musernamepoint
  musername = begin + (end - begin) / 2;
  unsigned n_iter = 1;

  while (begin != end and musername->getUsername() != player_username) {
    /* end is meant to be invalusername, so in both cases
     * we are ignoring musername at the following iteration
     */
    if (player_username < musername->getUsername())
      end = musername;
    else
      begin = musername + 1;

    musername = begin + (end - begin) / 2;
    ++n_iter;
  }

  std::cout << "Number of Iterations " << n_iter << "\n";

  timing::time_point finish = std::chrono::steady_clock::now();
  timing::elapsed_between(start, finish);

  if (musername != player_vec.end() and player_username == musername->getUsername()) {
    return true;
  } else {
    return false;
  }
}


    bool stl_binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username) {

        timing::time_point start = std::chrono::steady_clock::now();

        bool outSearch = std::binary_search(player_vec.begin(),player_vec.end(),Arcade::Player(player_username));

        timing::time_point finish = std::chrono::steady_clock::now();
        timing::elapsed_between (start, finish);

        return outSearch;

    }

    bool set_search(const std::set<Arcade::Player> &player_set, unsigned player_username) {

        timing::time_point start = std::chrono::steady_clock::now();

        std::set<Arcade::Player>::iterator iter = player_set.find(Arcade::Player(player_username));

        bool outSearch;

        if (iter != player_set.end())
            outSearch =  true;
        else
            outSearch = false;

        timing::time_point finish = std::chrono::steady_clock::now();
        timing::elapsed_between(start, finish);

        return outSearch;

    }

    bool map_search(const std::unordered_map<unsigned, Arcade::Player> &player_map, unsigned player_username) {

        timing::time_point start = std::chrono::steady_clock::now();

        std::unordered_map<unsigned, Arcade::Player>::const_iterator iter = player_map.find(player_username);

        bool outSearch;

        if (iter != player_map.end())
            outSearch =  true;
        else
            outSearch = false;

        timing::time_point finish = std::chrono::steady_clock::now();
        timing::elapsed_between(start, finish);

        return outSearch;

    }

}

