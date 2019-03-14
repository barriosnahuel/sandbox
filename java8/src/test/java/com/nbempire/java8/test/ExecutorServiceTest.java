package com.nbempire.java8.test;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import static org.junit.Assert.assertEquals;

public class ExecutorServiceTest {

    @Test
    public void invokeAny_is_synchronous() {
        ExecutorService executorService = Executors.newSingleThreadExecutor();

        List<Callable<String>> calls = new ArrayList<>();

        calls.add(() -> {
            throw new NullPointerException("OMG!");
        });
        calls.add(() -> "it's synchronous");

        String result = null;
        try {
            result = executorService.invokeAny(calls);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        assertEquals("it's synchronous", result);
    }
}
