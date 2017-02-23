package com.github.barriosnahuel.sandbox.android.feature.scrollinganimations;

import android.content.Context;
import android.support.design.widget.CollapsingToolbarLayout;
import android.support.v7.widget.Toolbar;
import android.util.AttributeSet;
import android.view.View;
import android.widget.TextView;
import com.github.barriosnahuel.sandbox.android.R;
import hugo.weaving.DebugLog;

/**
 * Created by Nahuel Barrios on 2/23/17.
 */

public class MyCollapsingToolbarLayout extends CollapsingToolbarLayout {

    /**
     * Called "m" because it's the same as {@link CollapsingToolbarLayout#mScrimsAreShown}.
     */
    private boolean mScrimsAreShown;

    @DebugLog
    public MyCollapsingToolbarLayout(final Context context) {
        super(context);
    }

    @DebugLog
    public MyCollapsingToolbarLayout(final Context context, final AttributeSet attrs) {
        super(context, attrs);
    }

    @DebugLog
    public MyCollapsingToolbarLayout(final Context context, final AttributeSet attrs, final int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    @DebugLog
    @Override
    public void setScrimsShown(final boolean shown, final boolean animate) {
        super.setScrimsShown(shown, animate);

        if (mScrimsAreShown != shown) {
            if (animate) {

                // TODO: 2/23/17 Stop finding it every time!
                Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
                int childCount = toolbar.getChildCount();
                for (int i = 0; i < childCount; i++) {
                    View child = toolbar.getChildAt(i);
                    if (child instanceof TextView) {
                        child.animate().alpha(shown ? 1 : 0).start();
                    }
                }
            } else {
                // TODO: 2/23/17 Replicate if block here without animating it
            }

            mScrimsAreShown = shown;
        }
    }
}
