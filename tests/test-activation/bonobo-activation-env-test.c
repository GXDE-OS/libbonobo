/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <bonobo-activation/bonobo-activation.h>
#include <bonobo-activation/bonobo-activation-private.h>
#include <bonobo/bonobo-main.h>

#define TEST_ASSERT_STR_EQUAL(value, refvalue)                          \
        if (value == NULL || strcmp (value, refvalue) != 0) {           \
                fprintf (stderr, "%s:%i: expected value %s but got %s.\n", \
                         __FILE__, __LINE__, refvalue, value? value : "(null)"); \
                return 2;                                               \
        }

int
main (int argc, char *argv[])
{
        CORBA_char *value;
	bonobo_init (&argc, argv);

        bonobo_activation_set_activation_env_value ("DISPLAY", ":0");
        value = _bonobo_activation_get_activation_env_value ("DISPLAY");
        TEST_ASSERT_STR_EQUAL(value, ":0");

        bonobo_activation_set_activation_env_value ("DISPLAY", ":0.0");
        value = _bonobo_activation_get_activation_env_value ("DISPLAY");
        TEST_ASSERT_STR_EQUAL(value, ":0.0");        

        return 0;
}
