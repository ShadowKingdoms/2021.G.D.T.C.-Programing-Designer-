using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public bool isRespon = false;
    public string strPrefabName;
    // Start is called before the first frame update
    void Start()
    {
        strPrefabName = objPlayer.name;
    }

    // Update is called once per frame
    void Update()
    {
        if (objPlayer == null)// && isRespon == false)
        {
            if (isRespon == false)
                StartCoroutine(ProcessTimmer());
        }
    }

    IEnumerator ProcessTimmer()
    {
        Debug.Log("ProcessTimmer 1");
        isRespon = true;
        yield return new WaitForSeconds(1);
        GameObject prefabPlayer = Resources.Load("Prefabs/"+strPrefabName) as GameObject;
        objPlayer = Instantiate(prefabPlayer, this.transform.position, Quaternion.identity);
        objPlayer.name = prefabPlayer.name;
        isRespon = false;
        Debug.Log("ProcessTimmer 2");
    }
}
