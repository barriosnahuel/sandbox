package com.nbempire.android.mvc.controller;

import android.util.Log;
import android.view.View;

import com.nbempire.android.mvc.R;
import com.nbempire.android.mvc.model.SearchModel;
import com.nbempire.android.mvc.view.SearchView;

import java.util.Observable;
import java.util.Observer;

/**
 * Created by nbarrios on 24/09/14.
 */
public class SearchController extends Observable implements View.OnClickListener {

    private static final String TAG = "SearchController";

    private SearchModel model;
    private SearchView view;

    public SearchController(SearchModel model, SearchView view) {
        this.model = model;
        this.view = view;

        bindControllerOnView();
        addObservers();
    }

    private void addObservers() {
        addObserver(new Searcher());
    }

    private class Searcher implements Observer {
        @Override
        public void update(Observable observable, Object object) {
            if (R.id.searchButton == ((View) object).getId()) {

                model.setQuery(view.getSearchQuery().getText().toString());
                model.find();

                Log.d(TAG, "Encontrados items: " + model.getResult().size());
            }
        }
    }

    private void bindControllerOnView() {
        view.bind(this);
    }


    @Override
    public void onClick(View v) {
        this.setChanged();
        this.notifyObservers(v);
    }
}
