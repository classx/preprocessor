# /* Copyright (C) 2001
#  * Housemarque Oy
#  * http://www.housemarque.com
#  *
#  * Distributed under the Boost Software License, Version 1.0. (See
#  * accompanying file LICENSE_1_0.txt or copy at
#  * http://www.boost.org/LICENSE_1_0.txt)
#  */
#
# /* Revised by Paul Mensonides (2002) */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef BOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
# define BOOST_PREPROCESSOR_ARITHMETIC_MOD_HPP
#
# include <boost/preprocessor/arithmetic/detail/div_base.hpp>
# include <boost/preprocessor/config/config.hpp>
# include <boost/preprocessor/control/iif.hpp>
# include <boost/preprocessor/facilities/identity.hpp>
# include <boost/preprocessor/logical/bitand.hpp>
# include <boost/preprocessor/logical/compl.hpp>
# include <boost/preprocessor/tuple/elem.hpp>
# include <boost/preprocessor/arithmetic/detail/is_maximum_number.hpp>
# include <boost/preprocessor/arithmetic/detail/is_minimum_number.hpp>
#
# /* BOOST_PP_MOD */
#
#    define BOOST_PP_MOD(x, y) \
            BOOST_PP_IIF(BOOST_PP_BITAND(BOOST_PP_DETAIL_IS_MINIMUM_NUMBER(x),BOOST_PP_COMPL(BOOST_PP_DETAIL_IS_MINIMUM_NUMBER(y))), \
            BOOST_PP_IDENTITY_N(x,2),BOOST_PP_MOD_CHECKMAX)(x,y)
#
#    define BOOST_PP_MOD_CHECKMAX(x, y) BOOST_PP_IIF(BOOST_PP_DETAIL_IS_MAXIMUM_NUMBER(y),BOOST_PP_MOD_CHECK_OTHER_MAX,BOOST_PP_MOD_DO)(x,y)
#
#    define BOOST_PP_MOD_CHECK_OTHER_MAX(x, y) BOOST_PP_IIF(BOOST_PP_DETAIL_IS_MAXIMUM_NUMBER(x),0,x)
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_MOD_DO(x, y) BOOST_PP_TUPLE_ELEM(3, 1, BOOST_PP_DIV_BASE(x, y))
# else
#    define BOOST_PP_MOD_DO(x, y) BOOST_PP_MOD_I(x, y)
#    define BOOST_PP_MOD_I(x, y) BOOST_PP_TUPLE_ELEM(3, 1, BOOST_PP_DIV_BASE(x, y))
# endif
#
# /* BOOST_PP_MOD_D */
#
#    define BOOST_PP_MOD_D(d, x, y) \
            BOOST_PP_IIF(BOOST_PP_BITAND(BOOST_PP_DETAIL_IS_MINIMUM_NUMBER(x),BOOST_PP_COMPL(BOOST_PP_DETAIL_IS_MINIMUM_NUMBER(y))), \
            BOOST_PP_IDENTITY_N(x,3),BOOST_PP_MOD_CHECKMAX_D)(d,x,y)
#
#    define BOOST_PP_MOD_CHECKMAX_D(d, x, y) BOOST_PP_IIF(BOOST_PP_DETAIL_IS_MAXIMUM_NUMBER(y),BOOST_PP_MOD_CHECK_OTHER_MAX_D,BOOST_PP_MOD_DO_D)(d,x,y)
#
#    define BOOST_PP_MOD_CHECK_OTHER_MAX_D(d, x, y) BOOST_PP_IIF(BOOST_PP_DETAIL_IS_MAXIMUM_NUMBER(x),0,x)
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_MOD_DO_D(d, x, y) BOOST_PP_TUPLE_ELEM(3, 1, BOOST_PP_DIV_BASE_D(d, x, y))
# else
#    define BOOST_PP_MOD_DO_D(d, x, y) BOOST_PP_MOD_D_I(d, x, y)
#    define BOOST_PP_MOD_D_I(d, x, y) BOOST_PP_TUPLE_ELEM(3, 1, BOOST_PP_DIV_BASE_D(d, x, y))
# endif
#
# endif
