package com.github.barriosnahuel.sandbox.kotlin.model

import org.assertj.core.api.Assertions.assertThat
import org.junit.jupiter.api.Test

internal class PersonTest {

    @Test
    fun `test project config`() = Unit

    @Test
    fun `test basic assertion`() {
        val nahu = Person("Nahuel", 29)
        assertThat(nahu.age).isEqualTo(29)
    }
}