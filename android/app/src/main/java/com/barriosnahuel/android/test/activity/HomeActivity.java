package com.barriosnahuel.android.test.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.barriosnahuel.android.test.R;


public class HomeActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.my_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    public void fadingActionBar(View view) {
        startActivity(new Intent(this, FadingActionBarActivity.class));
    }

    public void multipleScrolls(View view) {
        startActivity(new Intent(this, MultipleScrollsActivity.class));
    }

    public void quickReturn(View view) {
        startActivity(new Intent(this, QuickReturnActivity.class));
    }

    public void fadingActionBarWithQuickReturn(View view) {
        startActivity(new Intent(this, FadingActionBarWithQuickReturnActivity.class));
    }

    public void screenSlide(View view) {
        startActivity(new Intent(this, ScreenSlideActivity.class));
    }

    public void actionBar(View view) {
        startActivity(new Intent(this, ActionBarActivity.class));
    }
}
