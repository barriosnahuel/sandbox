package com.nbempire.android.mvc.view;

import android.app.Activity;
import android.widget.Button;
import android.widget.EditText;

import com.nbempire.android.mvc.R;
import com.nbempire.android.mvc.controller.SearchController;

/**
 * Created by nbarrios on 24/09/14.
 */
public class SearchView {

    private EditText searchQuery;
    private Button searchButton;

    protected Activity context;

    public SearchView(Activity context) {
        this.context = context;

//        defineViewOrientation???

        searchButton = (Button)context.findViewById(R.id.searchButton);
        searchQuery = (EditText)context.findViewById(R.id.searchQuery);
    }

    public void bind(SearchController listener) {
        searchButton.setOnClickListener(listener);
        searchQuery.setOnClickListener(listener);
    }

    public EditText getSearchQuery() {
        return searchQuery;
    }

    public void setSearchQuery(EditText searchQuery) {
        this.searchQuery = searchQuery;
    }

    public Button getSearchButton() {
        return searchButton;
    }

    public void setSearchButton(Button searchButton) {
        this.searchButton = searchButton;
    }
}
