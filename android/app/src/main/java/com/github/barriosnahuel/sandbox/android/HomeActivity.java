package com.github.barriosnahuel.sandbox.android;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import com.github.barriosnahuel.sandbox.android.feature.scrollinganimations.CustomScrollingAnimationsActivity;
import com.github.barriosnahuel.sandbox.android.feature.scrollinganimations.DefaultScrollingAnimationsActivity;

public class HomeActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
    }

    public void openCustomScrollingAnimations(View view) {
        startActivity(new Intent(this, CustomScrollingAnimationsActivity.class));
    }

    public void openDefaultScrollingAnimations(View view) {
        startActivity(new Intent(this, DefaultScrollingAnimationsActivity.class));
    }
}
