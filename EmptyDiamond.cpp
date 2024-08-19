#include <iostream>

/*
   Виведіть на екран ромб, який пустий всередині (приклад нижче). Його висоту вводить
   користувач. Це число обов'язково має бути більше за 2 та обов'язково має бути непарним.

   Наприклад якщо користувач введе висоту 5, то вивід буде наступним:
     *
    * *
   *   *
    * *
     *
*/

int main ()
{
    int height;
    do
    {
        std::cout << "Enter a height (not an even number): ";
        std::cin >> height;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(34567, '\n');
        }
    } while (height <= 2 || height % 2 == 0);

    /*                                                v
                                                      e
    height == 5; ->                                   r
            *       0 1 * 3 4                         t
           * *      0 * 2 * 4                         i
          *   *     * 1 2 3 *                         c
           * *      0 * 2 * 4                         a
            *       0 1 * 3 4       h o r i z o n t a l
    */

    const int centerRhombus = height / 2;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i <= centerRhombus)             // top of the diamond
            {
                if (j == centerRhombus - i || j == centerRhombus + i)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
            else                                // bottom of the diamond
            {
                if (j == i + centerRhombus - height + 1 || j == height - i + centerRhombus - 1)
                    std::cout << "*";
                else
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
