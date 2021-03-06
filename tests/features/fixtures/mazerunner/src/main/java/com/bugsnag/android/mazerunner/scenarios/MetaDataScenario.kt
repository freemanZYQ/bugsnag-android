package com.bugsnag.android.mazerunner.scenarios

import android.content.Context
import com.bugsnag.android.Bugsnag
import com.bugsnag.android.Configuration

/**
 * Sends a handled exception to Bugsnag, which includes custom metadata
 */
internal class MetaDataScenario(config: Configuration,
                                context: Context) : Scenario(config, context) {
    override fun run() {
        super.run()
        Bugsnag.notify(RuntimeException("MetaDataScenario"), {
            it.error?.addToTab("Custom", "foo", "Hello World!")
        })
    }

}
