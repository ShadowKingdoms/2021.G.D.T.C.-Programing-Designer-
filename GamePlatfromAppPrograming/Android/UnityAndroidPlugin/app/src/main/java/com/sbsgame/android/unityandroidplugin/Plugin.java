package com.sbsgame.android.unityandroidplugin;

import android.app.Activity;

public class Plugin {
    static Activity m_Activity = null;
    //유니티로부터 액티비티를 받음.
    void SetAcivity(Activity activity)
    {
        m_Activity = activity;
    }
    //유니티에 1000값을 리턴함
    int GetInt()
    {
        return 1000;
    }
}

