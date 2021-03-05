#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
    set_name("花间舞剑图", ({ "painting" }) );
    set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "卷");
        set("long", "一幅刚做好的花间舞剑图，墨彩似乎尚未感觉，隐隐流动，画上一白衣女子轻提宝剑，含笑俏立。衣襟仿佛随风而动，栩栩如生，笑语嫣然。\n");
		set("material", "paper");
		set("no_give",1);
		set("annie/by_hy_draw",1);
	}
    ::init_staff(1);

    set("wield_msg", "$N将$n卷成一卷，当作长棍挥舞。\n");


}
/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
