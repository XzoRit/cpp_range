#include <boost/test/unit_test.hpp>
#include <range/v3/algorithm/equal.hpp>
#include <range/v3/range/access.hpp>
#include <range/v3/view/join.hpp>
#include <vector>

BOOST_AUTO_TEST_CASE(range_join)
{
  using namespace ranges;

  const std::vector<std::vector<int>> ii{ { 1 }, { 2, 3 }, { 4, 5, 6 } };
  const auto& flatii{ view::join(ii) };
  BOOST_TEST(ranges::equal(flatii, (std::vector<int>{ 1, 2, 3, 4, 5, 6 })));

  const std::vector<std::vector<std::vector<int>>> iii{
    { { 1 }, { 2, 3 }, { 4, 5, 6 } }, { { 7, 8 }, { 9, 10 } }, { { 11, 12 } }
  };
  const auto& flatiii{ iii | view::join | view::join };
  BOOST_TEST(ranges::equal(
    flatiii, (std::vector<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 })));

  BOOST_TEST(*ranges::cbegin(flatiii) == 1);
}
