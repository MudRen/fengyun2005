// Silencer @ FY4 workgroup. Oct.2004

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青葫芦", ({ "hulu", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "
人是铁饭是钢，在风云里不吃不喝虽然不会饿死渴死，但所有的恢复都会停止，
所以当你的食物饮水少了就要及时补充。这是一个盛满甘泉水的青葫芦，你可
以用命令ｄｒｉｎｋ　ｈｕｌｕ来喝。如果喝完了呢，在有水源的地方（比如
说风云城里的凤凰客栈）可以用ｆｉｌｌ　ｈｕｌｕ来重新灌满。\n");
		set("unit", "个");
		set("value", 0);
		set("no_drop",1);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "甘泉水",
		"remaining": 60,
	]) );
}
