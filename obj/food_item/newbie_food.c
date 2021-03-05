// Silencer @ FY4 workgroup. Oct.2004

inherit ITEM;
inherit F_FOOD;
void create()
{
    	set_name("大馒头", ({ "mantou" }) );
    	set_weight(8000);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("long", "
人是铁饭是钢，在风云里不吃不喝虽然不会饿死渴死，但所有的恢复都会停止，
所以当你的食物饮水少了就要及时补充。这是一个香喷喷的大馒头，你可以用
命令ｅａｔ　ｍａｎｔｏｕ来吃。\n");
        	set("unit", "个");
        	set("value", 0);
        	set("no_drop", 1);
        	set("food_remaining", 100);
        	set("food_supply", 300);
    	}
    	::init_item();
}


