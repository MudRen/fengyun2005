#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG "大昭密文" NOR, ({ "dzmwen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("no_split",1);
            set("material", "paper");
            set("long", "一本大昭寺的密文：
吾寺舍利子不慎丢失，虽为赤松所盗，贫僧身为主持，
无可脱责，望活佛量罪而处。

				葛伦
");
          }

    ::init_item();
}
