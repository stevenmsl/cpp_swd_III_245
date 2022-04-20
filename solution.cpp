#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <set>
#include <cstring>
using namespace sol245;
using namespace std;

/*takeaways
  - the main difference between this and question 243
    is that w1 and w2 might be the same
  - we still count each occurrence of w1 and w2
    differently even though w1 and w2 might be the same

*/

int Solution::find(vector<string> &words, string w1, string w2)
{
  auto dist = INT_MAX;

  auto same = w1 == w2;

  auto visited = 0, visitng = 0, indexLastFound = -1;

  for (auto i = 0; i < words.size(); i++)
  {
    /* don't forget to reset this as if
       the word is not w1 or w2 we will
       not be doing anything
     */
    visitng = 0;
    if (words[i] == w1 || words[i] == w2)
      visitng = words[i] == w1 ? 1 : 2;

    /* check one more condition
      if w1 and w2 are the same
      - in this case visited will
        be the same as visiting
    */
    if (visited && visitng && (visited != visitng || same))
      dist = min(dist, i - indexLastFound);

    /* record what we have visited
     */
    if (visitng)
      visited = visitng, indexLastFound = i;
  }

  return dist;
}