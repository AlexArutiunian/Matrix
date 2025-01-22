### Решение задачи 1.1 для 3 варианта

#### Дано:
- **Прибор**: Фазометр  
- **Диапазон измерений**: -90° ... +90°  
- **Класс точности**: 1.5  

#### Формула для расчета абсолютной погрешности:
```
Δ = Диапазон измерений × (Класс точности / 100)
```

1. **Определяем диапазон измерений:**
```
Диапазон измерений = максимальное значение - минимальное значение
Диапазон измерений = (+90°) - (-90°) = 180°
```

2. **Рассчитываем абсолютную погрешность:**
```
Δ = 180° × (1.5 / 100)
Δ = 180° × 0.015 = 2.7°
```

#### Ответ:
Абсолютная погрешность измерений для фазометра в 3 варианте составляет:
```
Δ = 2.7°
```

Рассмотрим решение для **варианта 3** из таблицы 1.2:

### Данные:
1. **Для амперметра**:
   \[
   I_{им} = 500 \, \text{мА} = 0.5 \, \text{А}, \quad R_{им} = 100 \, \text{Ом}, \quad I = 5 \, \text{А}.
   \]

2. **Для вольтметра**:
   \[
   U_{им} = 1 \, \text{В}, \quad R_{им} = 100 \, \text{Ом}, \quad U = 15 \, \text{В}.
   \]

---

### 1. Расчет для амперметра:

1. Вычислим коэффициент \( k \):
   \[
   k = \frac{I}{I_{им}} = \frac{5}{0.5} = 10.
   \]

2. Найдем сопротивление шунта \( R_ш \):
   \[
   R_ш = \frac{R_{им}}{k - 1} = \frac{100}{10 - 1} = \frac{100}{9} \approx 11.11 \, \text{Ом}.
   \]

---

### 2. Расчет для вольтметра:

1. Вычислим коэффициент \( k \):
   \[
   k = \frac{U}{U_{им}} = \frac{15}{1} = 15.
   \]

2. Найдем дополнительное сопротивление \( R_\text{доп} \):
   \[
   R_\text{доп} = R_{им}(k - 1) = 100 \cdot (15 - 1) = 100 \cdot 14 = 1400 \, \text{Ом}.
   \]

---

### Ответ для варианта 3:
1. Сопротивление шунта для амперметра:  
   \[
   R_ш \approx 11.11 \, \text{Ом}.
   \]

2. Дополнительное сопротивление для вольтметра:  
   \[
   R_\text{доп} = 1400 \, \text{Ом}.
   \]

