package com.sbsgame.android.unityandroidplugin;

import android.app.Activity;

public class Plugin {
    static Activity m_cActivity = null;

    void SetAcivity(Activity activity)
    {
        m_cActivity = activity;
    }

    public int GetInit() {
       return 20210829;
    }
}