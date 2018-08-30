package com.bugsnag.android.mazerunner.scenarios;

import android.content.Context;

import com.bugsnag.android.Configuration;

import org.jetbrains.annotations.NotNull;

public class CXXTrapScenario extends Scenario {

    static {
        System.loadLibrary("entrypoint");
    }

    public native void crash();

    public CXXTrapScenario(@NotNull Configuration config, @NotNull Context context) {
        super(config, context);
    }

    @Override
    public void run() {
        super.run();
        String metadata = getEventMetaData();
        if (metadata != null && metadata.equals("non-crashy")) {
            return;
        }
        crash();
    }
}