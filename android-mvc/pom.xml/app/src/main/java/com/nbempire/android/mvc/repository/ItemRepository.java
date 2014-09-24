package com.nbempire.android.mvc.repository;

import com.nbempire.android.mvc.model.Item;

import java.util.List;

/**
 * Created by nbarrios on 24/09/14.
 */
public interface ItemRepository {
    public List<Item> findByTitulo(String titulo);
}
