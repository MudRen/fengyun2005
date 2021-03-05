#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB "生死簿" NOR, ({ "shengsibu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", @LONG
这是一本薄薄的小册子，封面上是三个朱笔古篆：生死簿。故老相传，得
簿之人可将自己的名字勾掉而得长生不老，但一个时辰内如不将之送到阴
曹地府还给朱笔判官，得主将被天雷击死。你战战兢兢地翻开簿子，大失
所望地发现里面全是密密麻麻的蝌蚪文，根本找不到你的名字！
LONG);
          }

    ::init_item();
}
