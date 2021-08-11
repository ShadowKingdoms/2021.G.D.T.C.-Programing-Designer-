using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIItemButton : MonoBehaviour
{
    public Text textItemName;
    public Image imgItemSprite;

    public void Set(Item.ITEM_KIND item_kind)
    {
        Debug.Log("GUIItemButton.Set:" + item_kind);
        Button button = this.GetComponent<Button>();
        button.onClick.AddListener( ()=>OnClickEvent(item_kind) );
    }

    public void OnClickEvent(Item.ITEM_KIND item_kind)
    {
        Debug.Log("GUIItemButton.OnClickEvent:" + item_kind);
        GameManager.GetInstance().EventItemUsePlayer(item_kind);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
