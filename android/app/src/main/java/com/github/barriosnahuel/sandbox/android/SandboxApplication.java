package com.github.barriosnahuel.sandbox.android;

import android.app.Application;
import com.facebook.stetho.Stetho;

/**
 * Created by Nahuel Barrios on 2/22/17.
 */
public class SandboxApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        Stetho.initializeWithDefaults(this);
    }
}
