package com.nbempire.java7.test;

import org.junit.Assert;
import org.junit.Test;

/**
 * TODO : Javadoc for
 * <p/>
 * Created on 19/04/14, at 15:15.
 *
 * @author Nahuel Barrios <barrios.nahuel@gmail.com>.
 */
public class SillyTests {

    @Test
    public void testSwitch() {
        Assert.assertFalse("Should return false", callSwitch(22));
        Assert.assertTrue("Should return true", callSwitch(23));
        Assert.assertTrue("Should return true", callSwitch(24));
        Assert.assertFalse("Should return false", callSwitch(25));
    }

    private boolean callSwitch(int key) {
        boolean enter = false;

        switch (key) {
            case 21:
                enter = false;
                break;
            case 22:
                enter = false;
                break;
            case 23:
            case 24:
                enter = true;
                break;
            case 25:
                enter = false;
        }

        return enter;
    }
}
