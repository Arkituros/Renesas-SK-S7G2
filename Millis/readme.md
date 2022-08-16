# How To Use

- Include millis.h to the main code;
- Using Renesas HAL create a timer object;
- use the function "millis_init([your timer object])";
- The function millis() returns the millis value;

## Example

- Example of the main code for the use of this library

<pre>
<code>/* HAL-only entry function */
#include "hal_data.h"
#include "millis.h"
        
uint16_t mili;

void hal_entry(void)
{
    millis_init (g_timer); //AGT Instance created with HAL
    while(1)
    {
        mili = millis();
    }
}</code>
</pre>

### [Created by Arkituros](https://github.com/Arkituros/ "Created by Arkituros")



