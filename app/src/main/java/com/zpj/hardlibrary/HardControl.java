package com.zpj.hardlibrary;

public class HardControl {
    public static native int ledCtrl(int which, int status);
    public static native int ledOpen();
    public static native void ledClose();

    /* 静态模块  加载C库 库名：hardcontrol */
    static {
        try {
            System.loadLibrary("hardcontrol");
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

}

