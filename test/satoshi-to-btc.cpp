/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include "command.hpp"

SX_USING_NAMESPACES()

BOOST_AUTO_TEST_SUITE(satoshi_to_btc__invoke)

BOOST_AUTO_TEST_CASE(satoshi_to_btc__invoke__0_satoshi__okay_output)
{
    // $ sx satoshi-to-btc
    SX_DECLARE_COMMAND(sx::extension::satoshi_to_btc);
    command.set_satoshi_argument(0);
    SX_REQUIRE_OKAY(command.invoke(output, error));
    SX_REQUIRE_OUTPUT("0\n");
}

BOOST_AUTO_TEST_CASE(satoshi_to_btc__invoke__4200000000_satoshi__okay_output)
{
    // $ sx satoshi-to-btc
    SX_DECLARE_COMMAND(sx::extension::satoshi_to_btc);
    auto satoshi = 42 * coin_price(1);
    command.set_satoshi_argument(satoshi);
    SX_REQUIRE_OKAY(command.invoke(output, error));
    SX_REQUIRE_OUTPUT("42\n");
}

BOOST_AUTO_TEST_CASE(satoshi_to_btc__invoke__max_money_satoshi__okay_output)
{
    // $ sx satoshi-to-btc
    SX_DECLARE_COMMAND(sx::extension::satoshi_to_btc);
    auto satoshi = max_money();
    command.set_satoshi_argument(satoshi);
    SX_REQUIRE_OKAY(command.invoke(output, error));
    SX_REQUIRE_OUTPUT("20999999.9769\n");
}

BOOST_AUTO_TEST_SUITE_END()