package com.nbempire.android.mvc.model;

import com.nbempire.android.mvc.repository.ItemRepository;
import com.nbempire.android.mvc.repository.impl.ItemRepositoryImpl;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * Created by nbarrios on 24/09/14.
 */
public class SearchModel {

    private String query;
    private List<Item> result;

    protected ItemRepository itemRepository;

    public SearchModel() {
        this.itemRepository = new ItemRepositoryImpl();
    }

    public void find() {
        result = itemRepository.findByTitulo(query);
    }

    public List<Item> getResult() {
        return result;
    }

    public String getQuery() {
        return query;
    }

    public void setQuery(String query) {
        this.query = query;
    }
}
