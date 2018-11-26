#include <string.h>

#include "../parse/token.h"

/**
 * @brief This structure is the call stack. It's purpuse is to check if one variable can be used in a scope.
 * 
 */
typedef struct Stack_t
{
    unsigned capacity; /**< The capacity in Token Array */
    unsigned capPos;   /**< The capacity in int baseTopArray */
    int posStack;      /**< The position of our Stack Array*/
    int posBaseTop;    /**< The position of our base/top pointer in baseTopArray*/
    Token *stack;      /**< The stack of Tokens */
    int *baseTopArray; /**< list of base/top pointer. Push 2, pop 2. Increase top one by one. When we call a new fonction, we push a new push with top value amd push a new top*/

} Stack;

// posBaseTop                                        capPos
// --------------------------------------------------
// | base | top | base | top | base | top |
// --------------------------------------------------
//
// -------------------------------------------------------
// | 0 (base old)| 3 (top old)| 3 (base new)| 7 (top new)|
// -------------------------------------------------------
//
// 21|            |
// 20|            |
// 19|            |
// 18|            |
// 17|            |
// 16|            |
// 15|            |
// 14|            |
// 13|            |
// 12|            |
// 11|            |
// 10|            |
//  9|            |
//  8|            |
//  7|------------| <= top (mwe)
//  6|     10     |
//  5|     b      |
//  4|     a      |
//  3|------------| <= top (old) base (new)
//  2|     b      | <= Call a function test(a, b, 10);
//  1|     a      |
//  0|     main   | <= base (old)
//   |------------|