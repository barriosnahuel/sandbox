package com.github.barriosnahuel.sandbox.android.feature.scrollinganimations;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.ViewStub;
import android.widget.TextView;
import com.github.barriosnahuel.sandbox.android.R;
import hugo.weaving.DebugLog;

public class CustomScrollingAnimationsActivity extends AppCompatActivity {

    private Toolbar toolbar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_custom_scrolling_animations);
        toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        ViewStub replace = (ViewStub) findViewById(R.id.custom_header);
        replace.setLayoutResource(R.layout.custom_header);
        replace.inflate();

        setupTitle();

        setupPrimaryAction();
    }

    @DebugLog
    private void setupTitle() {
        int childCount = toolbar.getChildCount();
        for (int i = 0; i < childCount; i++) {
            View child = toolbar.getChildAt(i);
            if (child instanceof TextView) {
                // Change alpha instead of visibility because in my custom layout I'm gonna be changing this
                child.setAlpha(0);
            }
        }
    }

    private void setupPrimaryAction() {
        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();
            }
        });
    }
}
